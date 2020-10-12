// Example program
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

bool launching = false;


void Launch() {
    int i = 0;
    std::string rockets[2] = { "Team Astro, Rocket 1", "Team Astro Rocket 2" };
    std::string names[2] = { "george", "ben" };

    using namespace std::literals::chrono_literals;

    while (!launching && i < 5) {



        for (i; i < 5; i++) {
            std::cout << rockets[i] << std::endl;
            std::this_thread::sleep_for(1s);
        }


    }




}

int main()
{
    std::thread launcher(Launch);

    std::cin.get();
    launching = true;

    launcher.join();

    std::cin.get();
}
