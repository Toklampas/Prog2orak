#include <iostream>
using namespace std;

class Aircraft {
protected:
    string name;
    int hatotav;
    double tanksize;
public:
    Aircraft(string pname, int phatotav, double ptanksize) : name(pname), hatotav(phatotav), tanksize(ptanksize) {}
    double getConsumptionPerKm()
    {
        return tanksize / hatotav;
    }
};

class JetAircraft : public Aircraft {
    int engines;

public:
    JetAircraft(string pname, int phatotav, double ptanksize, int pengines) : Aircraft(pname, phatotav, ptanksize), engines(pengines) {}
    double getConsumptionPerKm() {
        return (tanksize / hatotav) * (1 + 0.05 * engines);
    }
};

int main()
{
    JetAircraft a("probanev", 100, 20.0, 5);
    cout << a.getConsumptionPerKm();
    return 0;
}