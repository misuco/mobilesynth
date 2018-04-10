#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include <QObject>
#include "conf/types.h"
#include "conf/pitch.h"
#include "comm/libofqf/qoscclient.h"

class Heartbeat : public QObject
{
    Q_OBJECT
public:
    explicit Heartbeat(QObject *parent = nullptr);

protected:
    void timerEvent(QTimerEvent *event);

signals:

public slots:    
    void onSetRootNote(Pitch * p);
    void onSetBscale(int n, bool v);
    void onScaleSet(MWScale*scale);

private:
    MWScale _scale;
    QOscClient * _out;
    int _beatNo;
    int _scaleNo;
    int _scaleChangePropagated;
    int _timerId;

    void propagateScale();
};

#endif // HEARTBEAT_H