#include <iostream>
#include <thread>
//std::thread to launch a new thread


int rocketAmount = 10; 
std::string rocketHolder;
std::string nameHolder;
std::string fullText;
static bool superLock = false;
static bool complete = false;



//Function that begins to launch the rockets
void RocketLauncher()
{
    //Variable used for keeping track of the rockets.
    int i = 0;

    //The namespace that allows me to use chronos without std namespace
    using namespace std::literals::chrono_literals;

    //While main continues to await input, this while loop continues to run until the superLock is enabled, or until all 10 rockets are dispatched.
    while (!superLock && i <= 9) {
        //This for loop helps increment and keep the rockets launching in succession.
        for (i; i <= 9; i++) {
            if (!superLock) {
                //Arrays to hold the names of the Teams, Rockets, and their Pilots.
                std::string rockets[10] = { "Team Astro, Rocket 1", "Team Pepper, Rocket 2", "Team Sleepy, Rocket 3", "Team Rocket, Rocket 4", "Team Whatever, Rocket 5", "Team YOLO, Rocket 6", "Team Coffee, Rocket 7", "Team Pizza, Rocket 8", "Team Stargate, Rocket 9", "Team Believers, Rocket 10" };
                std::string pilots[10] = { "Jennifer Love Hewitt", "George Washington", "Michael Scott", "Someone's Mother", "Ronald McDonald", "Doctor Suess", "The Queen of England", "Dwayne Johnson", "Jeff Bezos", "Tony Hawk" };

                std::string tempHolder;
                tempHolder = rockets[i];
                rocketHolder = rockets[i];
                nameHolder = pilots[i];
                fullText = fullText + rockets[i] + " flown by " + pilots[i] + ", ";

                std::cout << tempHolder << " has been launched!" << std::endl;
                std::cout << "\nRocket holding in process for " << rocketHolder << std::endl;
                std::cout << "Rocket is currently being flown by " << nameHolder << std::endl;
                std::cout << "\nOur current squadron is now: " << fullText << std::endl;
                std::cout << "\nCurrent thread ID = " << std::this_thread::get_id() << std::endl;
                std::this_thread::sleep_for(1s);
                //Another check to see if the button has been pressed.
                if (superLock) {
                    return;
                }
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Currently processing information from " << tempHolder << std::endl;
                std::cout << "Press SPACE at any time to interrupt the launching sequence" << std::endl;
                std::cout << "Please hold";


                for (int i = 0; i < 3; i++)
                {
                    if (!superLock) {
                        std::cout << ".";
                        std::this_thread::sleep_for(1s); // this code tells the thread to sleep for 3 seconds. gives a neat waiting effect
                    }
                    else {
                        return;
                    }

                }
                std::cout << std::endl;
                std::cout << std::endl;
            }            
        }
    }   
    //locker.unlock(); //This finally unlocks the code for another thread
    return;
}



int main() {
    using namespace std::literals::chrono_literals;

    std::cout << "Time to smash some buttons!" << std::endl;
    std::cout << "\nCurrent thread ID = " << std::this_thread::get_id() << std::endl;
    std::cout << "Passing control over now, please initiate rockets ";
    
    for (int i = 1; i < rocketAmount; i++)
    {
        std::cout << i << ", ";
        std::this_thread::sleep_for(1s);
    }
    std::cout << "and 10." << std::endl;
    std::cout << std::endl;
    std::this_thread::sleep_for(1s);

    std::thread launcher(RocketLauncher);

    std::cin.get();
    
    std::cout << std::endl;
    std::cout << "***ABORT BUTTON PRESSED***" << std::endl;
    std::cout << "Control has now been passed back to the command center.";
    superLock = true;
    launcher.join();
    std::cout << "\nCurrent thread ID = " << std::this_thread::get_id() << std::endl;
    std::cout << "" << std::endl;

    std::cin.get();


}
