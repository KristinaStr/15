#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;

void pole(int array[4][4]) {
  for (int i = 0; i < 4; i++) {
    cout << " +----+----+----+----+" << endl;
    for (int j = 0; j < 4; j++) {
      if (array[i][j] < 10) {
        if (array[i][j] == 0) {
          if (j == 3) {
            cout << " | "
                 << "  "
                 << " | " << endl;
            break;
          }
          cout << " | "
               << "  ";
        } else if (j == 3) {
          cout << " | "
               << "0" << array[i][j] << " | " << endl;
          break;
        } else {
          cout << " | "
               << "0" << array[i][j];
        }
      } else if (j == 3) {
        cout << " | " << array[i][j] << " | " << endl;
        break;
      } else
        cout << " | " << array[i][j];
    }
  }
  cout << " +----+----+----+----+" << endl;
}

void greate(int array[4][4]) {
  int k = 1;
  while (k < 16) {
    int i = rand() % 4;
    int j = rand() % 4;
    if (array[i][j] == 0) {
      array[i][j] = k;
      k++;
    }
  }
}
void left(int array[4][4]) {
  bool sdvig = false;
  for (int i = 0; i < 4 && !sdvig; i++) {
    for (int j = 0; j < 4; j++) {
      if (array[i][j] == 0 && j > 0) {
        swap(array[i][j - 1], array[i][j]);
        sdvig = true;
        break;
      }
    }
  }
}
void right(int array[4][4]) {
  bool sdvig = false;
  for (int i = 0; i < 4 && !sdvig; i++) {
    for (int j = 0; j < 4; j++) {
      if (array[i][j] == 0 && j < 3) {
        swap(array[i][j + 1], array[i][j]);
        sdvig = true;
        break;
      }
    }
  }
}
void up(int array[4][4]) {
  bool sdvig = false;
  for (int i = 0; i < 4 && !sdvig; i++) {
    for (int j = 0; j < 4; j++) {
      if (array[i][j] == 0 && i > 0) {
        swap(array[i - 1][j], array[i][j]);
        sdvig = true;
        break;
      }
    }
  }
}
void down(int array[4][4]) {
  bool sdvig = false;
  for (int i = 0; i < 4 && !sdvig; i++) {
    for (int j = 0; j < 4; j++) {
      if (array[i][j] == 0 && i < 3) {
        swap(array[i + 1][j], array[i][j]);
        sdvig = true;
        break;
      }
    }
  }
}
bool win(int array[4][4]) {
  int k = 1;
  for (int i = 0; i < 4; i++) {
    if (k == 15) {
      break;
    }
    for (int j = 0; j < 4; j++) {
      if (k == 15) {
        break;
      }
      if (j < 3) {
        if (array[i][j] < array[i][j + 1]) {
          k++;
        } else {
          return false;
        }
      } else if (i < 3) {
        if (array[i][j] < array[i + 1][0]) {
          k++;
        } else {
          return false;
        }
      }
    }
  }
  return true;
}
int main() {
  char op;
  int array[4][4] = {};
  srand(time(NULL));
  greate(array);
  pole(array);
  while (cin >> op) {
    switch (op) {
      case 'h': {
        left(array);
        pole(array);
        break;
      }
      case 'l': {
        right(array);
        pole(array);
        break;
      }
      case 'k': {
        up(array);
        pole(array);
        break;
      }
      case 'j': {
        down(array);
        pole(array);
        break;
      }
      default: {
        cout << "Wrong simvol" << endl;
        break;
      }
    }
    if (win(array)) {
      cout << "WIN" << endl;
      return false;
    }
  }
}
