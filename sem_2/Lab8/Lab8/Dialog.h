#pragma once
#include "List.h"

// класс диалога (управление программой)
class Dialog : public List {
public:
    Dialog(void);
    virtual ~Dialog(void);

    virtual void GetEvent(TEvent& event); // получение события
    virtual int Execute(); // главный цикл
    virtual void HandleEvent(TEvent& event); // обработка события
    virtual void ClearEvent(TEvent& event); // очистка события

    int Valid(); // проверка завершения
    void EndExec(); // завершение работы

protected:
    int EndState; // состояние завершения
};