using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System;
using UnityEngine;

public class Link
{
    public GameObject Obj { get; set; }
    public Room Room1 { get; set; }
    public Room Room2 { get; set; }

    public Link(Room r1, Room r2)
    {
        Room1 = r1;
        Room2 = r2;
    }

    public static string GetLinkKey(string r1, string r2)
    {
        int cmp = r1.CompareTo(r2);

        if (cmp == 0)
            return (null);
        if (cmp > 0)
            return (r1 + "-" + r2);
        return (r2 + "-" + r1);
    }
    public static bool TryParseLink(string line, int i)
    {
        string r1, r2;
        Room room1, room2;

        r1 = line.Substring(0, i);
        r2 = line.Substring(i + 1);
        if (Farm.Rooms.ContainsKey(r1) && Farm.Rooms.ContainsKey(r2))
        {
            string key = GetLinkKey(r1, r2);
            if (r1 != r2 && !Farm.Links.ContainsKey(key))
            {
                room1 = Farm.Rooms[r1] as Room;
                room2 = Farm.Rooms[r2] as Room;
                room1.Links.Add(room2);
                room2.Links.Add(room1);
                Farm.Links.Add(key, new Link(room1, room2));
            }
            return (true);
        }
        return (false);
    }
    public static bool ParseLink(string line)
    {
        for (int i = 0; i < line.Length; i++)
        {
            if (line[i] == '-' && TryParseLink(line, i))
                return (true);
        }
        return (false);
    }

    private void InitializeEdgeTransform(GameObject link, Vector3 a, Vector3 b)
    {
        link.transform.position = (a + b) / 2f;
        a = a - b;
        link.transform.rotation = Quaternion.Euler(0, 0, -(a.y >= 0 ? (Mathf.Asin(a.x / (a.magnitude == 0 ? 1 : a.magnitude)) * 180f) / Mathf.PI : (Mathf.Acos(a.x / a.magnitude) * 180f) / Mathf.PI + 90f));
        link.transform.localScale = new Vector3(link.transform.localScale.x, a.magnitude / 2f, link.transform.localScale.z);
    }
    public void Instantiate(GameObject link)
    {
        Obj = link;
        InitializeEdgeTransform(link, Room1.Obj.transform.position, Room2.Obj.transform.position);
    }
}

public class Room
{
    public GameObject Obj { get; set; }
    public string Name { get; set; }
    public Vector3 Position { get; set; }
    public List<Room> Links { get; set; }
    public int CurMove { get; set; }

    public static int minX;
    public static int minY;
    public static int maxX;
    public static int maxY;
    private static float factorX;
    private static float factorY;
    private static float shiftX;
    private static float shiftY;

    public Room(string name, int x, int y)
    {
        Name = name;
        Position = new Vector3(x, y);
        Links = new List<Room>();
    }

    public static void SetScale()
    {
        Vector3 topright = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width * 0.7f, Screen.height * 0.85f, 10));
        Vector3 botleft = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width * 0.3f, Screen.height * 0.15f, 10));

        factorX = 2 * topright.x / (maxX - minX);
        factorY = 2 * topright.y / (maxY - minY);
        shiftX = (minX * factorX) - botleft.x / 1.1f;
        shiftY = (minY * factorY) - botleft.y;
    }
    private static void SetMin(int x, int y)
    {
        minX = Math.Min(minX, x);
        minY = Math.Min(minY, y);
        maxX = Math.Max(maxX, x);
        maxY = Math.Max(maxY, y);
    }
    public static bool ParseRoom(string line)
    {
        int s1, s2;
        string name;
        int x, y;
        Room r;

        s1 = -1;
        s2 = -1;
        for (int i = line.Length - 1; i >= 0; --i)
        {
            if (line[i] == ' ')
            {
                if (s2 == -1)
                    s2 = i;
                else
                {
                    s1 = i;
                    break;
                }
            }
        }
        if (s1 < 1 || s2 < 1)
            return (false);
        name = line.Substring(0, s1);
        x = System.Convert.ToInt32(line.Substring(s1 + 1, s2 - s1 - 1));
        y = System.Convert.ToInt32(line.Substring(s2 + 1));
        SetMin(x, y);
        r = new Room(name, x, y);
        Farm.Rooms.Add(name, r);
        Farm.ExecCmd(r);
        return (true);
    }

    public void Instantiate(GameObject room)
    {
        Position = new Vector3(Position.x * factorX - shiftX, Position.y * factorY - shiftY, Position.z);
        room.transform.position = Position;
        Obj = room;
    }
}

public struct Move
{
    public int Ant { get; set; }
    public Room Room { get; set; }

    private Room prevRoom;

    public static int CurMove;

    private static int ParseMove(string line, int i)
    {
        int istart;
        int ihyph;

        while (i < line.Length && line[i] != 'L')
            ++i;
        istart = i + 1;
        while (i < line.Length && line[i] != '-')
            ++i;
        ihyph = i;
        while (i < line.Length && line[i] != 'L')
            ++i;
        if (i == line.Length)
            Farm.Moves[Farm.Moves.Count - 1].Add(new Move()
            {
                Ant = Convert.ToInt32(line.Substring(istart, ihyph - istart)),
                Room = Farm.Rooms[line.Substring(ihyph + 1, i - ihyph - 1)] as Room
            });
        else
            Farm.Moves[Farm.Moves.Count - 1].Add(new Move()
            {
                Ant = Convert.ToInt32(line.Substring(istart, ihyph - istart)),
                Room = Farm.Rooms[line.Substring(ihyph + 1, i - ihyph - 2)] as Room
            });
        return (i);
    }
    public static void ParseMoveLine(string line)
    {
        int i = 0;
        Farm.Moves.Add(new List<Move>());
        while (i < line.Length)
            i = ParseMove(line, i);
    }

    public Ant Next(Ant[] ants, GameObject antPrefab)
    {
        Ant a;

        a = ants[Ant - 1];
        if (a == null)
        {
            a = new Ant(GameObject.Instantiate(antPrefab), Farm.StartRoom);
            ants[Ant - 1] = a;
        }
        if (a.Path.Count == Move.CurMove)
            a.Path.Add(Room);
        if (!Farm.Links.ContainsKey(Link.GetLinkKey(a.PrevRoom.Name, Room.Name)))
            return (null);
        if (Room != Farm.EndRoom && Room != Farm.StartRoom && Room.CurMove == Move.CurMove)
            return (null);
        Room.CurMove = Move.CurMove;
        return (a);
    }
}

public static class Farm
{
    private enum Cmd { None, Start, End };

    public static Room StartRoom;
    public static Room EndRoom;
    public static List<List<Move>> Moves;
    public static int AntCount;
    public static Hashtable Rooms;
    public static Hashtable Links;
    public static bool Created;

    private static Cmd command;
    private static bool parseRooms;

    static Farm()
    {
        Init();
    }
    static void Init()
    {
        command = Cmd.None;
        Rooms = new Hashtable();
        Links = new Hashtable();
        parseRooms = true;
        Moves = new List<List<Move>>();
        Created = false;

        Move.CurMove = 0;

        Room.minX = int.MaxValue;
        Room.minY = int.MaxValue;
        Room.maxX = int.MinValue;
        Room.maxY = int.MinValue;
    }

    public static void ExecCmd(Room r)
    {
        if (command == Cmd.Start)
            StartRoom = r;
        else if (command == Cmd.End)
            EndRoom = r;
        command = Cmd.None;
    }

    private static void ParseComment(string line)
    {
        if (line == "##start")
            command = Cmd.Start;
        if (line == "##end")
            command = Cmd.End;
    }
    private static void ParseFarmData(string line)
    {
        if (parseRooms)
        {
            if (!Room.ParseRoom(line))
                parseRooms = false;
        }
        if (!parseRooms)
        {
            Link.ParseLink(line);
        }
    }
    private static bool ConvertOutput(Process p)
    {
        string line;
        bool result;

        while ((line = p.StandardOutput.ReadLine()) != null)
            if (line[0] != '#')
                break;
        result = false;
        while ((line = p.StandardOutput.ReadLine()) != null)
        {
            if (line.Length > 0)
            {
                if (line[0] == '#')
                    ParseComment(line);
                else
                    ParseFarmData(line);
            }
            else
                break ;
            result = true;
        }
        while ((line = p.StandardOutput.ReadLine()) != null)
            Move.ParseMoveLine(line);
        return result;
    }

    public static bool ReadFarm(string inputFile, string lemIn, int antCount)
    {
        Process p = new Process();
        bool result = true;

        AntCount = antCount;
        p.StartInfo.UseShellExecute = false;
        p.StartInfo.RedirectStandardOutput = true;
        p.StartInfo.RedirectStandardError = true;
        p.StartInfo.FileName = "../" + lemIn;
        p.StartInfo.Arguments = String.Format("../{0} {1}", inputFile, antCount);
        p.Start();
        if (!ConvertOutput(p))
            result = false;
        p.WaitForExit();
        if (p.ExitCode != 0)
        {
            string err = p.StandardError.ReadToEnd();
            FarmBehaviour.ShowMessage(err);
        }
        return result;
    }
    public static void DestroyFarm(Ant[] ants)
    {
        if (Created)
        {
            foreach (var room in Rooms.Values)
                GameObject.Destroy((room as Room).Obj);
            foreach (var link in Links.Values)
                GameObject.Destroy((link as Link).Obj);
            foreach (var ant in ants)
                if (ant != null && ant.Obj != null)
                    GameObject.Destroy(ant.Obj);
            Init();
        }
    }

    public static void IstantiateRooms(GameObject roomPrefab)
    {
        Room.SetScale();
        foreach (var r in Farm.Rooms.Values)
            (r as Room).Instantiate(GameObject.Instantiate(roomPrefab));
    }
    public static void InstantiateLinks(GameObject linkPrefab)
    {
        foreach (var l in Farm.Links.Values)
            (l as Link).Instantiate(GameObject.Instantiate(linkPrefab));
    }
}