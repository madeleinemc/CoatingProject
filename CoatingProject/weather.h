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
    QString location; //location name
    int temp;
    int light_coat;
    int heavy_coat;

    QString get_from_html(QString marker, QString delimiter); //extract string from html

public:
    Weather(QString new_zipcode); //create Weather object using zipcode

    QString view_html();

    QString get_loc();

    int get_temp();

    int get_coat(); //0 = no coat, 1 = light coat, 2 = heavy coat
};

#endif // WEATHER_H
