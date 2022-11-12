#include <bits/stdc++.h>
using namespace std;
int studentCount = 0;
int eventCount = 0;
int volunteerCount = 0;
int participantCount = 0;

class Event;

class Student
{
public:
    int rollNo;
    string name;
    string phone;

    Student(int rollNo = ++studentCount, string name = "", string phone = "")
    {
        this->rollNo = rollNo;
        this->name = name;
        this->phone = phone;
    }
};

class Participant : public Student
{
public:
    int participantId;
    vector<Event *> events;

    Participant(int rollNo = ++studentCount, string name = "", string phone = "", int participantId = ++participantCount, vector<Event *> events = {})
    {
        this->rollNo = rollNo;
        this->name = name;
        this->phone = phone;
        this->participantId = participantId;
        this->events = events;
        for (auto i : events)
            i->addParticipant(this);
    }

    void participate(Event *event)
    {
        events.push_back(event);
        event->addParticipant(this);
    }
};

class Volunteer : public Student
{
public:
    int volunteerId = 0;
    string description = "";
    vector<Event *> volunteeredEvents = {};

    Volunteer(int rollNo = ++studentCount, string name = "", string phone = "", int volunteerId = ++volunteerCount, vector<Event *> events = {}, string description = "")
    {
        this->rollNo = rollNo;
        this->name = name;
        this->phone = phone;
        this->volunteerId = volunteerId;
        this->volunteeredEvents = events;
        this->description = description;

        for (auto i : events)
            i->addVolunteer(this);
    }

    void volunteer(Event *event)
    {
        volunteeredEvents.push_back(event);
        event->addVolunteer(this);
    }
};

class Coordinator : public Volunteer
{

public:
    vector<Event *> coordinatedEvents;

    Coordinator(int rollNo = ++studentCount, string name = "", string phone = "", int volunteerId = ++volunteerCount, vector<Event *> events = {}, string description = "")
    {
        this->rollNo = rollNo;
        this->name = name;
        this->phone = phone;
        this->volunteerId = volunteerId;
        this->coordinatedEvents = events;
        this->description = description;

        for (auto i : events)
            i->addCoordinator(this);
    }

    void coordinate(Event *event)
    {
        coordinatedEvents.push_back(event);
        event->addCoordinator(this);
    }
};

class Coremember : public Coordinator
{

public:
    vector<Event *> organisedEvents;

    Coremember(int rollNo = ++studentCount, string name = "", string phone = "", int volunteerId = ++volunteerCount, vector<Event *> events = {}, string description = "")
    {

        this->rollNo = rollNo;
        this->name = name;
        this->phone = phone;
        this->volunteerId = volunteerId;
        this->organisedEvents = events;
        this->description = description;

        for (auto i : events)
            i->addHead(this);
    }

    void organise(Event *event)
    {
        organisedEvents.push_back(event);
        event->addHead(this);
    }
};

class Event
{

public:
    int eventid;
    string name;
    vector<Participant *> participants;
    vector<Volunteer *> volunteers;
    vector<Coordinator *> coordinators;
    vector<Coremember *> heads;
    string time;

    Event(int eventid = ++eventCount, string name = "", string time = "")
    {
        this->eventid = eventid;
        this->name = name;
        this->time = time;
    }

    void addParticipant(Participant *participant)
    {
        participants.push_back(participant);
    }

    void addVolunteer(Volunteer *volunteer)
    {
        volunteers.push_back(volunteer);
    }

    void addCoordinator(Coordinator *coordinator)
    {
        coordinators.push_back(coordinator);
    }

    void addHead(Coremember *head)
    {
        heads.push_back(head);
    }
};

int main()
{

    Student student(1234, "Student", "9473536211");

    Event *event1 = &Event(1, "Event 1", "11:00 AM, 23-11-22");
    Event *event2 = &Event(2, "Event 2", "11:00 AM, 23-11-22");
    Event *event3 = &Event(3, "Event 3", "11:00 AM, 23-11-22");

    Participant participant(1222, "Participant", "955648213", 104, {event1});
    participant.participate(event2);
    participant.participate(event3);

    Volunteer volunteer(1223, "volunteer", "123456789", 1, {event1}, "GoodGuy");
    volunteer.volunteer(event2);
    volunteer.volunteer(event3);

    Coordinator coordinator(1334, "coordinator", "123456789", 2, {event1}, "BadGuy");
    coordinator.coordinate(event2);
    coordinator.coordinate(event3);

    Coremember coremember(1556, "coremember", "987654321", 3, {event1}, "Deligient");
    coremember.organise(event2);
    coremember.organise(event3);

    Event event(4, "Event", "10:00 AM, 23-11-22");
    event.addParticipant(&participant);
    event.addVolunteer(&volunteer);
    event.addCoordinator(&coordinator);
    event.addHead(&coremember);

    return 0;
}