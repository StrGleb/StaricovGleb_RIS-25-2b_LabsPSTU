#include "Dialog.h"

Dialog::Dialog(void) : Tree() { EndState = 0; }
Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event) {
    string OpInt = "+-szqm";
    string s;
    cout << ">" << ' '; cin >> s;
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
        if (s.length() > 1) event.a = stoi(s.substr(1));
    }
    else event.what = evNothing;
}

int Dialog::Execute() {
    TEvent event;
    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);
    } while (!Valid());
    return EndState;
}

int Dialog::Valid() { return (EndState == 0) ? 0 : 1; }
void Dialog::ClearEvent(TEvent& event) { event.what = evNothing; }
void Dialog::EndExec() { EndState = 1; }

void Dialog::HandleEvent(TEvent& event) {
    if (event.what == evMessage) {
        switch (event.command) {
        case cmMake:
            cout << "Tree created. Current size: " << cur << endl;
            ClearEvent(event);
            break;
        case cmAdd: Add(); ClearEvent(event); break;
        case cmDel: Del(); ClearEvent(event); break;
        case cmShow: Show(); ClearEvent(event); break;
        case cmQuit: EndExec(); ClearEvent(event); break;
        default: Tree::HandleEvent(event); ClearEvent(event);
        }
    }
}