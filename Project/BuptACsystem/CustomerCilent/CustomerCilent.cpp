#include "CustomerCilent.h"
CustomerCilent::CustomerCilent(QWidget *parent)
    : QMainWindow(parent)
{
    QString butname1 = "��һ����ť";
    ui.setupUi(this);
    ui.pushButton->setText(butname1);
    setWindowTitle("�����ؿյ�������");
}
