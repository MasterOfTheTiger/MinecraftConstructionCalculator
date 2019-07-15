#include <iostream>
#include <string>
using namespace std;

int height, wall, widthf, widths, roof, tfloor, slanted, total;
string answer;
void admin();
int calculator();
int searchCommands(string entered);
int main()
{
    cout << "This is the Minecraft Construction Calculator. Version Alpha 0.1.\n If you are using this then you are using then you ought to know that this is still being made and might have many bugs.\n I will update it a lot in the coming days/weeks/months.\n If you have any questions, comments, or bug reports please email jallestad12@gmail.com. \n\n Thank you for trying this program.\n\n\n";
    cout << "Enter 'C' to continue.\n\n";
    string answer;
    cin >> answer;
    if (answer == "admin") {
        admin();
    } else{
      while (true) {
        cout << "\n\n\n\n";
        cout << "Calculator starting..." << "\n\n";
        calculator();
      }
      return 0;
    }
}
int calculator() {
  //Calculator:
  do {
    cout << "What is the height of your structure (In blocks)? ";
    cin >> height;
    cout << "Okay. " << height << " is the height. Are you sure? [y/n] ";
    cin >> answer;
    cout << "\n\n";
  } while ( !(answer == "y"));
  do {
    cout << "What is the width of the front wall? (In blocks)? ";
    cin >> widthf;
    cout << "Okay. " << widthf << " is the width for your front wall. Are you sure? [y/n] ";
    cin >> answer;
    cout << "\n\n";
  } while ( !(answer == "y"));
  do {
    cout << "What is the width of the side wall? (In blocks)? ";
    cin >> widths;
    cout << "Okay. " << widths << " is the width for your side wall. Are you sure? [y/n] ";
    cin >> answer;
    cout << "\n\n";
  } while ( !(answer == "y"));
  do {
    cout << "Do you want a slanted roof? [y/n] ";
    cin >> answer;
    if (answer == "y") {
      slanted = 2;
    } else {
      slanted = 1;
    }
    if (slanted == 2) {
      cout << "You want a slanted roof. Are you sure? [y/n] ";
    } else {
      cout << "You don't want a slanted roof. Are you sure? [y/n] ";
    }
    cin >> answer;
    cout << "\n\n";
  } while ( !(answer == "y"));
  roof = (widthf - 2) * (widths - 2) * slanted;
  tfloor = (widthf - 2) * (widths - 2);
  wall = (widthf * height * 2) + (widths - 2 * height * 2);
  cout << "The amount you need for your roof and floor is " << roof + tfloor << " blocks. \n The amount you need for your walls is " << wall << " blocks.\n";
  total = roof + wall + tfloor;
  cout << "The total amount you need for your structure is " << total << " blocks.\n\n\n\n";
  return total;
}
string commands[2]={"test", "calculator"};
void admin() {
  cout << "Welcome to the Admin room! Here you can enter commands of all kinds.\n";
  while (true) {
    cout << "Enter a command:\n";
    cin >> answer;
    searchCommands(answer);
  }
}

int searchCommands(string entered) {
  int x=-1;
  do {
    x++;
  } while (!(commands[x] == entered));
  cout << "INFORMATION: x = " << x << ". This is for debugging only.\n";
  switch (x) {
    case 0:
    cout << "If you can see this, then the test went well.\n";
    break;
    case 1:
    cout << "Calculator it is.\n\n\n\n";
    calculator();
    cout << "Back to the admin room.\n\n\n";
    break;
    default:
    cout << "There is no command by the name of '" << entered << "' in the database.\n";
  }
  return x;
}
