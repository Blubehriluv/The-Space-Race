#include <iostream>
#include <thread>
#include <mutex>
#include <string>
using namespace std;
//std::thread to launch a new thread


int rocketAmount = 10; 
string rocketHolder;
string nameHolder;
string fullText;
mutex locker; //This is just to lock and unlock the code that all the threads are trying to use at the same time.
bool superLock = false;

void AbortButton() {
    while (superLock == false) {
        int a;
        cin >> a;
        if (a == '\n') {
            cout << "wowie" << endl;
        }
          
    }
        
}

void RocketLauncher(string whichRocket, string whichPilot)
{

    locker.lock(); //Only one thread can run the code at a time (until unlocked)
    string tempHolder;  
    tempHolder = whichRocket;
    rocketHolder = whichRocket;
    nameHolder = whichPilot;
    fullText = fullText + whichRocket + " flown by " + whichPilot + ", ";

    string userinput;

    cout << tempHolder << " has been launched!" << endl;
    cout << "\nRocket holding in process for " << rocketHolder << endl;
    cout << "\nRocket is currently being flown by " << nameHolder << endl;
    cout << "\nOur entire team is now: " << fullText << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Currently processing information from " << tempHolder << endl;
    cout << "Press SPACE at any time to interrupt the launching sequence" << endl;
    cout << "Please hold";


    for (int i = 0; i < 3; i++)
    {
        cout << ".";        
        this_thread::sleep_for(chrono::seconds(1)); // this code tells the thread to sleep for 3 seconds. gives a neat waiting effect
    }
    cout << endl;
    cout << endl;
    cout << endl;
    locker.unlock(); //This finally unlocks the code for another thread
}



int main() {
    cout << "Time to smash some buttons!" << endl;
    cout << "Passing control over now, please initiate rockets ";
    /*
    for (int i = 1; i < rocketAmount; i++)
    {
        cout << i << ", ";
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "and 10." << endl;
    this_thread::sleep_for(chrono::seconds(1));*/
    AbortButton();

    thread r1{ RocketLauncher,"Team Astro, Rocket 1", "Jennifer Love Hewitt" };

    thread r2{ RocketLauncher,"Team Pepper, Rocket 2", "George Washington" };

    thread r3{ RocketLauncher,"Team Sleepy, Rocket 3", "Michael Scott"};

    thread r4{ RocketLauncher,"Team Rocket, Rocket 4","Someone's Mother"};

    thread r5{ RocketLauncher,"Team Whatever, Rocket 5", "McJagger"};

    thread r6{ RocketLauncher,"Team YOLO, Rocket 6", "Doctor Seuss" };

    thread r7{ RocketLauncher,"Team Coffee, Rocket 7", "The Queen of England" };

    thread r8{ RocketLauncher,"Team Pizza, Rocket 8", "Dwayne Johnson" };

    thread r9{ RocketLauncher,"Team Stargate, Rocket 9", "Jeff Bezos" };

    thread r10{ RocketLauncher,"Team Believers, Rocket 10", "Tony Hawk" };


    //Checking to make sure the thread is joinable.
    if (r1.joinable())
    {
        cout << "\nThread one is joinable!" << endl;
        r1.join();
    }
    if (r2.joinable())
    {
        cout << "\nThread two is joinable!" << endl;
        r2.join();
    }
    if (r3.joinable())
    {
        cout << "\nThread three is joinable!!" << endl;
        r3.join();
    }
    if (r4.joinable())
    {
        cout << "\nThread four is joinable!" << endl;
        r4.join();
    }
    if (r5.joinable())
    {
        cout << "\nThread five is joinable!" << endl;
        r5.join();
    }
    if (r6.joinable())
    {
        cout << "\nThread six is joinable!" << endl;
        r6.join();
    }
    if (r7.joinable())
    {
        cout << "\nThread seven is joinable!" << endl;
        r7.join();
    }
    if (r8.joinable())
    {
        cout << "\nThread eight is joinable!" << endl;
        r8.join();
    }
    if (r9.joinable())
    {
        cout << "\nThread nine is joinable!" << endl;
        r9.join();
    }
    if (r10.joinable())
    {
        cout << "\nThread ten is joinable!" << endl;
        r10.join();
    }

    cout << "Control has now been passed back to the command center." << endl;
    cout << "" << endl;


    system("pause");

    return 0;
}
