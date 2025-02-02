#include <iostream>    // For input/output operations
#include <string>      // For string manipulation
#include <cstdlib>     // For rand() and srand() functions
#include <ctime>       // For time() function to seed random generator/display time
#include <algorithm>   // For transform() to handle case insensitivity
#include <iomanip>     // For setting precision
using namespace std;

// Random message arrays
string greetings[] = { "Hi! Ready to work?", "Hello! Need help?",
                     "Greetings!", "Welcome!", "How can I assist?" };
string goodbyes[] = { "Goodbye!", "See you!", "Farewell!",
                    "Bye!", "Have a great day!" };

// Function to get random messages
string getRandomMessage(const string arr[], int size) {
    return arr[rand() % size];
}

int main() {
    srand(time(0)); // Initialize random number generator
    string input;

    // Initial greeting with random message
    cout << "UtilityBot: " << getRandomMessage(greetings, 5)
        << "\nType 'help' for commands\n";

    while (true) {
        cout << "\nYou: ";
        getline(cin, input);

        // Convert input to lowercase for case-insensitive commands
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        // Handle exit command
        if (input == "bye" || input == "9") {
            cout << "UtilityBot: " << getRandomMessage(goodbyes, 5) << "\n";
            break;
        }

        // Display help menu
        if (input == "help" || input == "0") {
            cout << "Available commands:\n"
                << "1. hello       - New Greeting\n"
                << "2. calculator  - Math/Health\n"
                << "3. converter   - Unit Conversions\n"
                << "4. clock       - Time/Alarm/Stopwatch\n"
                << "5. password    - Generator/Strength Checker\n"
                << "6. random      - Random Generators\n"
                << "7. games       - Fun Mini-Games\n"
                << "8. todo        - Task Manager\n"
                << "9. bye         - Exit Program\n";
        }

        // Handle greeting command
        else if (input == "hello" || input == "1") {
            cout << "UtilityBot: " << getRandomMessage(greetings, 5) << "\n";
        }

        // Handle empty input
        else if (input.empty()) {
            cout << "UtilityBot: Please enter a command\n";
        }
        // Handle calculator command
        else if (input == "calculator" || input == "2") {
            cout << "UtilityBot: Calculator Modes:\n"
                << "1. Basic Math\n2. BMI\n3. Age\n4. Tip\n5. Factorial\n"
                << "Enter mode number: ";
            string mode;
            getline(cin, mode);

            if (mode == "1" || mode == "basic") {
                // Basic arithmetic operations
                double num1, num2;
                char op;
                cout << "Enter expression (e.g., 5 + 3): ";
                cin >> num1 >> op >> num2;

                switch (op) {
                case '+':
                    cout << "Result: " << num1 + num2 << endl;
                    break;
                case '-':
                    cout << "Result: " << num1 - num2 << endl;
                    break;
                case '*':
                    cout << "Result: " << num1 * num2 << endl;
                    break;
                case '/':
                    if (num2 != 0) cout << "Result: " << num1 / num2 << endl;
                    else cout << "Error: Division by zero!" << endl;
                    break;
                default:
                    cout << "Invalid operator!" << endl;
                }
                cin.ignore(); // Clear input buffer
            }
            else if (mode == "2" || mode == "bmi") {
			    // BMI Calculator
			    double weight, heightCm;
			    cout << "Enter weight (kg) and height (cm): ";
			    cin >> weight >> heightCm;
			    
			    double heightM = heightCm / 100;  // Convert cm to meters
			    double bmi = weight / (heightM * heightM);
			    
			    cout << "BMI: " << bmi << " - ";
			    
			    // Simple health status check
			    if (bmi < 18.5) {
			        cout << "Underweight (Eat more!)";
			    }
			    else if (bmi < 25) {
			        cout << "Healthy (Good job!)"; 
			    }
			    else if (bmi < 30) {
			        cout << "Overweight (Exercise needed)";
			    }
			    else {
			        cout << "Obese (Consult doctor)";
			    }
			    
			    cin.ignore();
			}
            else if (mode == "3" || mode == "age") {
                // Age Calculator
                int birthYear, birthMonth, birthDay;
			    cout << "Enter birth date (YYYY MM DD): ";
			    cin >> birthYear >> birthMonth >> birthDay;
			    
			    // Get current date
			    time_t now = time(nullptr);
			    tm ltm{};
			    localtime_s(&ltm, &now);
			    int currentYear = 1900 + ltm.tm_year;
			    int currentMonth = ltm.tm_mon + 1;  // tm_mon is 0-11
			    int currentDay = ltm.tm_mday;
			
			    // Calculate age
			    int age = currentYear - birthYear;
			    
			    // Check if birthday hasn't occurred yet this year
			    if (currentMonth < birthMonth || 
			        (currentMonth == birthMonth && currentDay < birthDay)) {
			        age--;
   				}
   				cout << "Age: " << age << " years\n";
    			cin.ignore();
            }
            else if (mode == "4" || mode == "tip") {
			    // Tip Calculator
			    double bill, tipPercent;
			    cout << "Enter bill amount and tip percentage: ";
			    cin >> bill >> tipPercent;
			    
			    double tip = bill * (tipPercent / 100);
			    cout << "Tip amount: " << tip << "\n";
			    cout << "Total with tip: " << bill + tip << "\n";
			    
			    cin.ignore();
			}
			else if (mode == "5" || mode == "factorial") {
                // Factorial Calculator
                int n;
                cout << "Enter number: ";
                cin >> n;
                long result = 1;
                for (int i = 1; i <= n; i++) result *= i;
                cout << n << "! = " << result << endl;
                cin.ignore();
            }
        }

        // Handle converter command
        else if (input == "converter" || input == "3") {
			    cout << "UtilityBot: Conversion Types:\n"
			         << "1. Currency\n2. Temperature\n3. Length\n"
			         << "Enter type number: ";
			    string type;
			    getline(cin, type);
			
			    cout << fixed << setprecision(2);  // Set decimal format for all conversions
			
			    if (type == "1" || type == "currency") {
			        // Enhanced Currency Converter
			        cout << "Available currencies:\n"
			             << "1. USD (US Dollar)\n"
			             << "2. EUR (Euro)\n"
			             << "3. GBP (British Pound)\n"
			             << "4. PKR (Pak Rupee)\n"
			             << "5. INR (Indian Rupee)\n"
			             << "6. JPY (Japanese Yen)\n"
			             << "7. CNY (Chinese Yuan)\n";
			
			        int fromCurr, toCurr;
			        double amount;
			        
			        cout << "Enter FROM currency (1-7): ";
			        cin >> fromCurr;
			        cout << "Enter TO currency (1-7): ";
			        cin >> toCurr;
			        cout << "Enter amount: ";
			        cin >> amount;
			
			        // Exchange rates relative to USD (base currency)
			        const double rates[] = {
			            1.0,      // USD
			            0.85,     // EUR
			            0.73,     // GBP
			            280.0,    // PKR
			            82.0,     // INR
			            110.0,    // JPY
			            6.5       // CNY
			        };
			
			        // Convert to USD first
			        double usdAmount = amount / rates[fromCurr-1];
			        // Convert to target currency
			        double result = usdAmount * rates[toCurr-1];
			
			        string currencies[] = {"USD", "EUR", "GBP", "PKR", "INR", "JPY", "CNY"};
			        cout << amount << " " << currencies[fromCurr-1]
			             << " = " << result << " " << currencies[toCurr-1] << "\n";
			    }
			    else if (type == "2" || type == "temperature") {
			        // Temperature Conversion with decimal precision
			        double temp;
			        char unit;
			        cout << "Enter temperature and unit (C/F): ";
			        cin >> temp >> unit;
			
			        if (toupper(unit) == 'C') {
			            double f = (temp * 9/5) + 32;
			            cout << temp << "°C = " << f << "°F\n";
			        }
			        else if (toupper(unit) == 'F') {
			            double c = (temp - 32) * 5/9;
			            cout << temp << "°F = " << c << "°C\n";
			        }
			        else {
			            cout << "Invalid unit! Use C or F\n";
			        }
			    }
			    else if (type == "3" || type == "length") {
			        // Length Conversion with precision
			        double value;
			        string unit;
			        cout << "Enter value and unit (m/ft): ";
			        cin >> value >> unit;
			
			        if (unit == "m" || unit == "meters") {
			            double feet = value * 3.28084;
			            cout << value << " m = " << feet << " ft\n";
			        }
			        else if (unit == "ft" || unit == "feet") {
			            double meters = value / 3.28084;
			            cout << value << " ft = " << meters << " m\n";
			        }
			        else {
			            cout << "Invalid unit! Use m or ft\n";
			        }
			    }
			    cin.ignore();
			}
        
        // Handle clock command
        else if (input == "clock" || input == "4") {
            cout << "UtilityBot: Clock Features:\n"
                << "1. Current Time\n2. Timer\n3. Stopwatch\n"
                << "Enter mode number: ";
            string mode;
            getline(cin, mode);

            if (mode == "1" || mode == "time") {
                // Current time display
                time_t now = time(nullptr);
                tm ltm{};
                localtime_s(&ltm, &now);
                cout << "Current Time: "
                    << ltm.tm_hour << ":"
                    << ltm.tm_min << ":"
                    << ltm.tm_sec << "\n";
            }
            else if (mode == "2" || mode == "timer") {
                // Countdown timer
                int seconds;
                cout << "Enter timer duration (seconds): ";
                cin >> seconds;
                cin.ignore();

                time_t start = time(0);
                while (difftime(time(0), start) < seconds) {
                    cout << "Time remaining: "
                        << seconds - difftime(time(0), start)
                        << " seconds\r";
                    cout.flush();
                }
                cout << "\nTime's up! \a\n"; // \a triggers system beep
            }
            else if (mode == "3" || mode == "stopwatch") {
                // Stopwatch with lap tracking
                cout << "Press Enter to start/stop\n";
                cin.ignore(); // Wait for first Enter

                time_t start = time(0);
                cout << "Stopwatch started...\n";
                cin.get(); // Wait for second Enter

                double elapsed = difftime(time(0), start);
                cout << "Elapsed time: " << elapsed << " seconds\n";
            }
        }


        // Handle password command
        else if (input == "password" || input == "5") {
            cout << "UtilityBot: Password Tools:\n"
                << "1. Generate\n2. Check Strength\n"
                << "Enter tool number: ";
            string tool;
            getline(cin, tool);

            if (tool == "1" || tool == "generate") {
                // Password Generator
                int length;
                cout << "Enter password length (8-50): ";
                cin >> length;
                cin.ignore();

                if (length < 8 || length > 50) {
                    cout << "Invalid length! Using default 12 characters\n";
                    length = 12;
                }

                string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz"
                    "0123456789!@#$%^&*";
                string password;
                for (int i = 0; i < length; i++) {
                    password += chars[rand() % chars.size()];
                }
                cout << "Generated Password: " << password << "\n";
            }
            else if (tool == "2" || tool == "check") {
                // Password Strength Checker
                string password;
                cout << "Enter password to check: ";
                getline(cin, password);

                int strength = 0;
                bool hasUpper = false, hasLower = false;
                bool hasDigit = false, hasSpecial = false;

                for (char c : password) {
                    if (isupper(c)) hasUpper = true;
                    if (islower(c)) hasLower = true;
                    if (isdigit(c)) hasDigit = true;
                    if (!isalnum(c)) hasSpecial = true;
                }

                if (password.length() >= 8) strength++;
                if (password.length() >= 12) strength++;
                if (hasUpper && hasLower) strength++;
                if (hasDigit) strength++;
                if (hasSpecial) strength++;

                cout << "Password Strength: " << strength << "/5\n";
                if (strength<5){
					cout << "Recommendations:\n";
	                if (!hasUpper) cout << "- Add uppercase letters\n";
	                if (!hasLower) cout << "- Add lowercase letters\n";
	                if (!hasDigit) cout << "- Add numbers\n";
	                if (!hasSpecial) cout << "- Add special characters\n";
	            }
            }
        }

        // Handle random command
        else if (input == "random" || input == "6") {
            cout << "UtilityBot: Random Generators:\n"
                << "1. Number\n2. Coin\n3. Dice\n4."
                << "Enter generator number: ";
            string gen;
            getline(cin, gen);

            if (gen == "1" || gen == "number") {
                // Random Number Generator
                int min, max;
                cout << "Enter min and max values: ";
                cin >> min >> max;
                cout << "Random Number: "
                    << min + (rand() % (max - min + 1)) << "\n";
                cin.ignore();
            }
            else if (gen == "2" || gen == "coin") {
                // Coin Flip
                cout << "Result: " << (rand() % 2 ? "Heads" : "Tails") << "\n";
            }
            else if (gen == "3" || gen == "dice") {
                // Dice Roll
                cout << "Rolled: " << (rand() % 6 + 1) << "\n";
            }
        }
        // Handle games command
        else if (input == "games" || input == "7") {
            cout << "UtilityBot: Available Games:\n"
                << "1. Guess the Number\n2. Tic-Tac-Toe\n"
                << "Enter game number: ";
            string game;
            getline(cin, game);

            if (game == "1" || game == "guess") {
                // Number Guessing Game
                int secret = rand() % 100 + 1;
                int attempts = 0;
                cout << "I'm thinking of a number between 1-100\n";

                while (true) {
                    int guess;
                    cout << "Your guess: ";
                    cin >> guess;
                    attempts++;

                    if (guess == secret) {
                        cout << "Correct! You won in " << attempts << " tries!\n";
                        cin.ignore();
                        break;
                    }
                    cout << "Too " << (guess < secret ? "low" : "high") << "!\n";
                }
            }
            else if (game == "2" || game == "tictactoe") {
                // Tic-Tac-Toe Game
                char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
                int moves = 0;

                cout << "Tic-Tac-Toe (Use numpad positions)\n";
                while (true) {
                    // Display board
                    for (int i = 0; i < 3; i++) {
                        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
                        if (i < 2) cout << "-----------\n";
                    }

                    // Player move
                    int pos;
                    cout << "Enter position (1-9): ";
                    cin >> pos;
                    pos--;
                    int row = pos / 3, col = pos % 3;

                    if (pos < 0 || pos>8 || board[row][col] > '8') {
                        cout << "Invalid move!\n";
                        continue;
                    }
                    board[row][col] = 'X';
                    moves++;

                    // Check win
                    if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
                        (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
                        (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
                        (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
                        (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
                        (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
                        (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
                        (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
                        cout << "You win!\n";
                        break;
                    }
                    if (moves == 9) {
                        cout << "It's a draw!\n";
                        break;
                    }

                    // AI move
                    cout << "AI's turn...\n";
                    while (true) {
                        int aiPos = rand() % 9;
                        row = aiPos / 3;
                        col = aiPos % 3;
                        if (board[row][col] <= '9') {
                            board[row][col] = 'O';
                            moves++;
                            break;
                        }
                    }
                }
                cin.ignore();
            }
        }

        // Handle todo command
        else if (input == "todo" || input == "8") {
            static string tasks[10];
            static int taskCount = 0;

            cout << "Todo Commands:\nadd <task>\nlist\nremove <num>\n";
            string cmd;
            getline(cin, cmd);

            if (cmd.find("add ") == 0) {
                if (taskCount < 10) {
                    tasks[taskCount++] = cmd.substr(4);
                    cout << "Task added!\n";
                }
                else {
                    cout << "Todo list full!\n";
                }
            }
            else if (cmd == "list") {
                for (int i = 0; i < taskCount; i++) {
                    cout << i + 1 << ". " << tasks[i] << "\n";
                }
            }
            else if (cmd.find("remove ") == 0) {
                int num = stoi(cmd.substr(7)) - 1;
                if (num >= 0 && num < taskCount) {
                    for (int i = num; i < taskCount - 1; i++) {
                        tasks[i] = tasks[i + 1];
                    }
                    taskCount--;
                    cout << "Task removed!\n";
                }
                else {
                    cout << "Invalid task number!\n";
                }
            }
        }

        // Final else for unknown commands
        else {
            cout << "UtilityBot: Command not recognized. Type 'help' for options.\n";
             }
    }

    return 0;
}