#ifndef SETCHECK_H
#define SETCHECK_H

#include <QDialog>

namespace Ui {
class setcheck;
}

class setcheck : public QDialog
{
    Q_OBJECT
    
public:
    explicit setcheck(QWidget *parent = 0);
    ~setcheck();
    
protected slots:
    void okButton();

private:
    Ui::setcheck *ui;
};

#endif // SETCHECK_H
