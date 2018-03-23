using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MoveCoroutineParams
{
    public Ant ant;
    public Vector3 start;
    public Vector3 end;

    public MoveCoroutineParams(Ant ant, Vector3 start, Vector3 end)
    {
		this.ant = ant;
        this.start = start;
        this.end = end;
    }
}
public class Ant
{
	public GameObject Obj { get; set; }
	public Room PrevRoom { get; set; }
	public List<Room> Path { get; set; }
	public Queue<MoveCoroutineParams> MoveCoroutines;

	public Ant(GameObject obj, Room prev)
	{
		Obj = obj;
		PrevRoom = prev;
		obj.transform.position = prev.Obj.transform.position;
		Path = new List<Room>();
		for (int i = 0; i < Move.CurMove - 1; ++i)
			Path.Add(null);
		Path.Add(prev);
		MoveCoroutines = new Queue<MoveCoroutineParams>();
	}
}

public class FarmBehaviour : MonoBehaviour
{
	public const float lerpTime = 0.7f;

    public InputField InputFile;
	public InputField AntCount;
    public string LemIn;
	public GameObject RoomPrefab;
	public GameObject LinkPrefab;
	public GameObject AntPrefab;
	public Material RoomStartMat;
	public Material RoomEndMat;
	public Ant[] Ants;

	private int busyCount;
	private bool isPaused;
	private int antCount;

	private static bool displayMessage;
	private static string messageText;

    private void Start()
    {
        Transform[] allChildren = GetComponentsInChildren<Transform>();
        Text text;

        foreach (Transform child in allChildren)
        {
            if ((text = child.GetComponent<Text>()) != null)
                text.fontSize = (14 * Screen.width) / 1532;
        }
    }

	private void SetRoomMat(GameObject r, Material m)
	{
        r.GetComponent<Renderer>().material = m;
		r.transform.localScale = new Vector3(0.9f, 0.21f, 0.9f);
	}
	public void CreateFarm()
	{
		DestroyFarm();
		antCount = System.Convert.ToInt32(AntCount.text);
		if (Farm.ReadFarm(InputFile.text, LemIn, antCount))
		{
			Farm.IstantiateRooms(RoomPrefab);
			Farm.InstantiateLinks(LinkPrefab);
			SetRoomMat(Farm.StartRoom.Obj, RoomStartMat);
			SetRoomMat(Farm.EndRoom.Obj, RoomEndMat);
			Ants = new Ant[Farm.AntCount];
			isPaused = false;
			Farm.Created = true;
		}
	}
	public void DestroyFarm()
	{
		StopAllCoroutines();
		Farm.DestroyFarm(Ants);
	}

    private static float EaseInOutCubic(float start, float end, float value)
    {
        value /= .5f;
        end -= start;
        if (value < 1) return end * 0.5f * value * value * value + start;
        value -= 2;
        return end * 0.5f * (value * value * value + 2) + start;
    }

    private IEnumerator MoveObj(MoveCoroutineParams p)
    {
		float currentLerpTime = 0f;

		++busyCount;
        while (currentLerpTime <= 1f)
        {
            currentLerpTime += Time.deltaTime / lerpTime;
            p.ant.Obj.transform.position = Vector3.Lerp(p.start, p.end, EaseInOutCubic(0.0f, 1.0f, currentLerpTime));
            yield return null;
        }
        p.ant.MoveCoroutines.Dequeue();
		if (p.ant.MoveCoroutines.Count > 0)
		{
			var next = p.ant.MoveCoroutines.Peek();
			StartCoroutine(MoveObj(next));
		}
		--busyCount;
    }
	private void NextMove(Move move)
	{
		Ant a = move.Next(Ants, AntPrefab);
		if (a == null)
		{
			ShowMessage("MOVE ERROR");
			StopMoves();
		}
		else
		{
            a.MoveCoroutines.Enqueue(new MoveCoroutineParams(a, a.PrevRoom.Obj.transform.position, move.Room.Obj.transform.position));
            if (a.MoveCoroutines.Count == 1)
                StartCoroutine(MoveObj(a.MoveCoroutines.Peek()));
            a.PrevRoom = move.Room;
		}
	}
	private void PrevMove(Ant a)
	{
		if (a != null)
		{
			if (a.Path.Count > Move.CurMove && a.Path[Move.CurMove] != null)
			{
                a.MoveCoroutines.Enqueue(new MoveCoroutineParams(a, a.PrevRoom.Obj.transform.position, a.Path[Move.CurMove].Obj.transform.position));
				if (a.MoveCoroutines.Count == 1)
					StartCoroutine(MoveObj(a.MoveCoroutines.Peek()));
				a.PrevRoom.CurMove = Move.CurMove;
				a.PrevRoom = a.Path[Move.CurMove];
			}
		}
	}
    private IEnumerator StartMovesCoroutine()
	{
        while (Move.CurMove != Farm.Moves.Count)
        {
            NextMoveLine();
			while (busyCount != 0)
				yield return (null);
			if (isPaused)
				break;
        }
	}

	private bool Check()
	{
        if (!Farm.Created)
            return false;
		isPaused = false;
		return true;
	}
	public void StartMoves()
	{
        if (!Check())
            return;
        if (antCount != System.Convert.ToInt32(AntCount.text))
            CreateFarm();
        busyCount = 0;
		StartCoroutine(StartMovesCoroutine());
	}
	public void PauseMoves()
	{
        if (!Check())
            return;
		isPaused = true;
	}
	public void StopMoves()
	{
        if (!Check())
            return;
		PauseMoves();
		StopAllCoroutines();
		for (int i = 0; i < Ants.Length; ++i)
		{
			if (Ants[i] != null)
				GameObject.Destroy(Ants[i].Obj);
			Ants[i] = null;
		}
        Move.CurMove = 0;
		foreach (var r in Farm.Rooms.Values)
			(r as Room).CurMove = 0;
	}
	public void NextMoveLine()
	{
        if (!Check())
            return;
		if (Move.CurMove == Farm.Moves.Count)
			return;
        ++Move.CurMove;
		foreach (var m in Farm.Moves[Move.CurMove - 1])
			NextMove(m);
	}
    public void PrevMoveLine()
    {
        if (!Check())
            return;
		if (Move.CurMove == 0)
			return;
		--Move.CurMove;
        foreach (var a in Ants)
            PrevMove(a);
    }

    private static IEnumerator MessageCoroutine()
    {
        yield return (new WaitForSeconds(2f));
        displayMessage = false;
    }
    private void OnGUI()
    {
        if (displayMessage)
        {
            GUIStyle messageStyle = new GUIStyle();
			messageStyle.normal.textColor = Color.white;
            messageStyle.alignment = TextAnchor.MiddleCenter;
            messageStyle.fontSize = (25 * Screen.width) / 1532;
            var rect = new Rect(Screen.width / 2 - Screen.width / 16,
                            Screen.height / 2 - Screen.height / 32,
                            Screen.width / 8,
                            Screen.height / 16);
            GUI.Box(rect, messageText, messageStyle);
            StartCoroutine(MessageCoroutine());
        }
    }
    public static void ShowMessage(string text)
    {
        messageText = text;
        displayMessage = true;
    }
}
