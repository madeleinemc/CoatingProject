#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>


class QNetworkAccessManager;
class QUrl;
class Weather
{  
private:
    QString zipcode; //location of the weather
    QString html; //page source of weather.com for today @zipcode

public:
    Weather(QString new_zipcode);

    QString view_html();
};

#endif // WEATHER_H
