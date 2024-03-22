#include <iostream>
#include <exception>
#include <string>
#include <cstring>

using namespace std;

enum ProjectTopics
{
    NONE,
    // Students
    BACK_TO_THE_ROOTS,
    HACK_YOUR_HOBBY,
    INFINITE_OCEAN,
    SMART_SCHOOL,

    // Graduates
    CIVIC_TECH,
    // TODO: add one more topic for the graduates
};

class Team
{
protected:
    uint numberOfParticipants;
    const char *name;
    string mentorName;
    string projectName;
    ProjectTopics projectTopic;

    virtual bool isTeamFull() const
    {
        return false;
    }

public:
    Team(const char *name, const string &capitanName)
    {
        this->name = strdup(name);
        this->numberOfParticipants = 1;
        this->mentorName = "";
        this->projectName = "";
        projectTopic = ProjectTopics::NONE;
    }
    Team(const Team &other)
        : numberOfParticipants(other.numberOfParticipants), name(strdup(other.name)), mentorName(other.mentorName), projectName(other.projectName), projectTopic(other.projectTopic)
    {
    }

    Team &operator=(const Team &other)
    {
        if (this != &other)
        {
            delete this->name;
            this->name = strdup(other.name);

            this->mentorName = other.mentorName;
            this->numberOfParticipants = other.numberOfParticipants;
            this->projectName = other.projectName;
            this->projectTopic = other.projectTopic;
        }

        return *this;
    }

    ~Team()
    {
        delete this->name;
    }

    const char *getTeamName() const
    {
        return this->name;
    }

    const string &getProjectName() const
    {
        return this->projectName;
    }

    void addParticipant()
    {
        if (this->isTeamFull())
        {
            throw invalid_argument("Team is already full");
        }
        this->numberOfParticipants++;
    }
};

class StudentsTeam : public Team
{

    bool isTeamFull() const override
    {
        return this->numberOfParticipants >= 5;
    }
};

class GraduatesTeam
{
};

int main()
{

    return 0;
}