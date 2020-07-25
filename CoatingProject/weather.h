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
    int temp;
    int light_coat;
    int heavy_coat;

    QString get_temp_str(); //extract temp from html

public:
    Weather(QString new_zipcode); //create Weather object using zipcode

    QString view_html();

    int get_temp();

    int get_coat(); //0 = no coat, 1 = light coat, 2 = heavy coat
};

#endif // WEATHER_H
