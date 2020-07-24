#include "weather.h"

Weather::Weather(QString new_zipcode)
{
    zipcode = new_zipcode;

    QUrl url = QUrl(QString("https://weather.com/weather/today/l/%1").arg(zipcode));

    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(url));
    QEventLoop event;
    QObject::connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    html = response->readAll(); // Source should be stored here
}

QString Weather::view_html(){
    return html;
}

QString Weather::get_temp(){

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
