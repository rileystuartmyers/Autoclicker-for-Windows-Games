#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <cmath>

int main() {

    // wasd = []
    // clicking action    

    Sleep(3000);

    std::vector<char> directions {'w', 'a', 's', 'd'};

    while (true) {

        int rand_int = rand() % (2);
        int rand_time = rand() % (150) + 1000;

        if (GetAsyncKeyState(VK_RCONTROL)) {

            std::cout << "Terminating..." << std::endl;
            Sleep(1000);
            std::cout << "Done!" << std::endl;

            return 0;

        }

        if (rand_int == 1) { // mouse event

            INPUT input = {0};

            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &input, sizeof(input));

            ZeroMemory(&input, sizeof(input));

            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &input, sizeof(input));

            std::cout << "CLICK " << rand_time << std::endl;

        } else { // keyboard event

            int rand_sub_action = rand() % (3);
            char random_direction = directions[rand_sub_action];
            
            for (int i = 0; i < 2; ++i) {

                INPUT input = {0};

                input.type = INPUT_KEYBOARD;
                input.ki.wVk = VkKeyScanA(random_direction);

                SendInput(1, &input, sizeof(input));
                
                ZeroMemory(&input, sizeof(input));

                input.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &input, sizeof(input));

            }       

            std::cout << random_direction << " " << rand_time << std::endl;

        }

        Sleep(rand_time);

    }
    
   return 0;

};