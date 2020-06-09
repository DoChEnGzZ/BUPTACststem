#pragma once
#include"queueRequestObject.h"
#include"queueServiceObject.h"
#include <QObject>
#include<qtimer.h>

class Scheduler : public QObject
{
	Q_OBJECT
private:
	int defaultMode;
	float defaultTemp;
	int defaultFanSpeed;
	float hightlimitTemp;
	float lowlimitTemp;
public:
	Scheduler(QObject *parent);
	~Scheduler();
	QTimer *timer;
	queueRequestObject WaitQueue=new queueRequestObject(this);
	queueServiceObject ServiceQueue = new queueServiceObject(this);
	//���ÿ�������
	void setParm(int mode, float temp, int speed, float htemp, float ltemp);
	/*
	todo����ɴ����ݿ��в�ѯ�ϴη��õĺ���
	*/
	void requestOn(int RoomID);

	void requestOff(int RoomID);
	/*
	todo:���ݷ���ֵѡ����û����޸��¶ȵ�����سɹ�/���ڵ��·�Χ��ACK
	*/
	bool changetargetTemp(int RoomID, float targetTemp);
	/*
	todo:��ɵ���
	*/
	void changeFanSpeed(int RoomID, int FanSpeed);
	//�����ݿ���д��������
	void changeCurrentTemp(int RoomID, float CurrentTemp);
	/*
	�ۺ���:endwork
	����ɣ� 2.������Ϣд�����ݿ�
	*/
	void endwork(int ServeID);
	/*
	�ۺ�����endwait
	����ɣ� 2. ������Ϣд�����ݿ�
	*/
	void endwait(int WaitID);
signals:
	void turnonOK(int, float, int, bool);
	void turnonEROOR(int, bool);
	void turnOffOK(int,bool);
	void changeTempBack(int, bool);
	void changeFanSpeedBack(int, bool);
	void serviceStart(int, int);
	void serviceFinish(int);
	void waitStart(int, int, int);
	void keepAlive(int, int , float);
	/*
	todo: ���ݿ�������ź�
	*/
};
