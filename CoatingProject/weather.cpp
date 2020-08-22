#include "weather.h"

Weather::Weather(QString new_zipcode)
{
    zipcode = new_zipcode;


    //make it so these can be changed by user (Under "Advanced" settings?)
    light_coat = 60;
    heavy_coat = 30;


    //extract html
    QUrl url = QUrl(QString("https://weather.com/weather/today/l/%1").arg(zipcode));

    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(url));
    QEventLoop event; //see if this can be achieved w/out event, so code is more explicity asynchronous
    QObject::connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    html = response->readAll(); // Source should be stored here

    temp = (get_temp_str()).toInt();
}

QString Weather::view_html(){
    return html;
}

QString Weather::get_temp_str(){

    //the text that precedes temperature val in the html
    QString marker = "class=\"_-_-components-src-organism-CurrentConditions-CurrentConditions--tempValue--MHmYY\">";

    //get index of the temperature
    int marker_index = html.indexOf(marker);
    int temp_index = marker_index + marker.length();
    int degree_index = html.indexOf("°", temp_index);

    //format string based on indices
    QString html_copy = html;
    html_copy.remove(0,temp_index);
    html_copy.remove(degree_index-temp_index, html_copy.length());
    QString temp = html_copy;

    return temp;
}

int Weather::get_temp(){
    return temp;
}

//int is faster than string
int Weather::get_coat(){
    if (temp >= light_coat) return 0;
    if (temp >= heavy_coat) return 1;
    else return 2;
}
