#include "assignment_no_9.h"
#include "ui_assignment_no_9.h"
QImage j(600,600,QImage::Format_RGB888);
#include <math.h>

Assignment_No_9::Assignment_No_9(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Assignment_No_9)
{
    ui->setupUi(this);
}

Assignment_No_9::~Assignment_No_9()
{
    delete ui;
}

void Assignment_No_9::DDA_Line(float x1,float y1,float x2,float y2)
{
  //DDA Line Drawing Algorithm
  float step, dx, dy, i, x, y;
  dx = x2-x1;
  dy = y2-y1;
  if(abs(dx)>=abs(dy))
    {
      step = abs(dx);
    }
  else
    {
      step = abs(dy);
    }
  x = x1;
  y = y1;
  i = 0;
  dx = (dx/step);
  dy = (dy/step);
  while (i<=step)
    {
      j.setPixel((x),(y),qRgb(0,255,255));
      x = x + dx;
      y = y + dy;
      i++;
    }
}

void Assignment_No_9::on_pushButton_clicked()
{
    //Drawing rectangle
    float x_1,y_1,l,b;
    x_1 = ui->textEdit->toPlainText().toFloat();
    y_1 = ui->textEdit_2->toPlainText().toFloat();
    l = ui->textEdit_3->toPlainText().toFloat();
    b = ui->textEdit_4->toPlainText().toFloat();
    float x[5] = {x_1, x_1+l, x_1+l, x_1,x_1};
    float y[5] = {y_1, y_1, y_1+b, y_1+b,y_1};
    for(int i = 0;i<4;i++)
    {
        DDA_Line(x[i],y[i],x[i+1],y[i+1]);
    }
    ui->label->setPixmap(QPixmap::fromImage(j));
}


void Assignment_No_9::on_pushButton_2_clicked()
{
    //Translation
    float x_1,y_1,l,b;
    float Tx,Ty;
    x_1 = ui->textEdit->toPlainText().toFloat();
    y_1 = ui->textEdit_2->toPlainText().toFloat();
    l = ui->textEdit_3->toPlainText().toFloat();
    b = ui->textEdit_4->toPlainText().toFloat();


    Tx = ui->textEdit_5->toPlainText().toFloat();
    Ty = ui->textEdit_7->toPlainText().toFloat();
    float x[5] = {x_1, x_1+l, x_1+l, x_1,x_1};
    float y[5] = {y_1, y_1, y_1+b, y_1+b,y_1};
    for(int i = 0;i<5;i++)
    {
        x[i] = x[i] + Tx;
        y[i] = y[i] + Ty;
    }
    for(int i = 0;i<4;i++)
    {
        DDA_Line(x[i],y[i],x[i+1],y[i+1]);
    }
    ui->label->setPixmap(QPixmap::fromImage(j));
}
int g[2][2],h[2][1];
void Assignment_No_9::operator*(Assignment_No_9)
{
    //Overloading * operator for matrix multiplication..
    Assignment_No_9 x;
    int i,j,k;
    for (i=0;i<2;i++)
    {
        for (j=0;j<1;j++)
        {
            h[i][j] = 0;
            for (k = 0;k<2;k++)
            {
                h[i][j] = h[i][j] + (g[i][k]*h[k][j]);
            }
        }

    }
}
void Assignment_No_9::on_pushButton_3_clicked()
{
    //Scaling
    float x_1,y_1,l,b;
    float sx,sy;
    x_1 = ui->textEdit->toPlainText().toFloat();
    y_1 = ui->textEdit_2->toPlainText().toFloat();
    l = ui->textEdit_3->toPlainText().toFloat();
    b = ui->textEdit_4->toPlainText().toFloat();
    sx = ui->textEdit_6->toPlainText().toFloat();
    sy = ui->textEdit_8->toPlainText().toFloat();
    float a[2][2];
    a[0][0] = sx;
    a[0][1] = 0;
    a[1][0] = 0;
    a[1][1] = sy;
    float c[2][1];
    c[0][0] = l;
    c[1][0] = b;
    c[0][0] = a[0][0]*c[0][0];
    c[1][0] = a[1][1]*c[1][0];
    DDA_Line(x_1,y_1,x_1+c[0][0],y_1);
    DDA_Line(x_1+c[0][0],y_1,x_1+c[0][0],y_1+c[1][0]);
    DDA_Line(x_1+c[0][0],y_1+c[1][0],x_1,y_1+c[1][0]);
    DDA_Line(x_1,y_1+c[1][0],x_1,y_1);
    ui->label->setPixmap(QPixmap::fromImage(j));
}



void Assignment_No_9::on_pushButton_4_clicked()
{
    //rotation
    float x_1,y_1,l,b;
    float rot;
    x_1 = ui->textEdit->toPlainText().toFloat();
    y_1 = ui->textEdit_2->toPlainText().toFloat();
    l = ui->textEdit_3->toPlainText().toFloat();
    b = ui->textEdit_4->toPlainText().toFloat();


    rot = ui->textEdit_9->toPlainText().toFloat();
    rot = (rot*3.14)/180;
    float x[5] = {x_1, x_1+l, x_1+l, x_1,x_1};
    float y[5] = {y_1, y_1, y_1+b, y_1+b,y_1};
    for(int i = 0;i<5;i++)
    {
            x[i] = (x[i]*cos(rot))-(y[i]*sin(rot));
            y[i] = (x[i]*sin(rot))+(y[i]*cos(rot));
    }
    for(int i = 0;i<4;i++)
    {
        DDA_Line(x[i],y[i],x[i+1],y[i+1]);
    }
    ui->label->setPixmap(QPixmap::fromImage(j));
}

