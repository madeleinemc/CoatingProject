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

    //get location and temp from html
    QString loc_marker = "<title data-react-helmet=\"true\">";
    QString loc_delimiter = ",";
    location = get_from_html(loc_marker, loc_delimiter);
    QString temp_marker = "class=\"_-_-components-src-organism-CurrentConditions-CurrentConditions--tempValue--MHmYY\">";
    QString temp_delimiter = "°";
    temp = get_from_html(temp_marker, temp_delimiter).toInt();
}

QString Weather::view_html(){
    return html;
}

/* [get_from_html marker delimiter] returns the string in between the first instance of marker
 * and the first instance of delimiter after marker
*/
QString Weather::get_from_html(QString marker, QString delimiter){

    //get index of the temperature
    int marker_index = html.indexOf(marker);
    int target_index = marker_index + marker.length();
    int degree_index = html.indexOf(delimiter, target_index);

    //format string based on indices
    QString html_copy = html;
    html_copy.remove(0,target_index);
    html_copy.remove(degree_index-target_index, html_copy.length());
    QString target = html_copy;

    return target;
}

QString Weather::get_loc(){
    return location;
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
