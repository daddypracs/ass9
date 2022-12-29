#ifndef ASSIGNMENT_NO_9_H
#define ASSIGNMENT_NO_9_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Assignment_No_9; }
QT_END_NAMESPACE

class Assignment_No_9 : public QMainWindow
{
    Q_OBJECT

public:
    Assignment_No_9(QWidget *parent = nullptr);
    ~Assignment_No_9();
    void DDA_Line(float,float,float,float);
    void operator*(Assignment_No_9);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Assignment_No_9 *ui;
};
#endif // ASSIGNMENT_NO_9_H
