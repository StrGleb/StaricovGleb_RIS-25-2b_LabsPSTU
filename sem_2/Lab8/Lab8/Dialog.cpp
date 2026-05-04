#include "Dialog.h"

Dialog::Dialog(void) : List() {
    EndState = 0; // начальное состояние
}

Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event) {
    string OpInt = "+-szqm";
    string s;

    cout << ">" << ' ';
    cin >> s;

    char code = s[0];

    if (OpInt.find(code) != string::npos) {
        event.what = evMessage;

        switch (code) {
        case 'm': event.command = cmMake; break;
        case '+': event.command = cmAdd; break;
        case '-': event.command = cmDel; break;
        case 's': event.command = cmShow; break;
        case 'z': event.command = cmGet; break;
        case 'q': event.command = cmQuit; break;
        }

        if (s.length() > 1)
            event.a = stoi(s.substr(1));
    }
    else event.what = evNothing;
}

// главный цикл программы
int Dialog::Execute() {
    TEvent event;

    do {
        EndState = 0;

        GetEvent(event);       // получить событие
        HandleEvent(event);   // обработать событие

    } while (!Valid());

    return EndState;
}

// проверка завершения
int Dialog::Valid() {
    return (EndState == 0) ? 0 : 1;
}

// очистка события
void Dialog::ClearEvent(TEvent& event) {
    event.what = evNothing;
}

// завершение программы
void Dialog::EndExec() {
    EndState = 1;
}

// обработчик событий
void Dialog::HandleEvent(TEvent& event) {
    if (event.what == evMessage) {
        switch (event.command) {

        case cmMake:
            Clear(); // очистка списка
            beg = nullptr;
            cur = 0;
            cout << "List created\n";
            ClearEvent(event);
            break;

        case cmAdd:
            Add();
            ClearEvent(event);
            break;

        case cmDel:
            Del();
            ClearEvent(event);
            break;

        case cmShow:
            Show();
            ClearEvent(event);
            break;

        case cmQuit:
            EndExec();
            ClearEvent(event);
            break;

        default:
            List::HandleEvent(event); // передача события
            ClearEvent(event);
        }
    }
}