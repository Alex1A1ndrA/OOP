#include <string>

bool fear(const std::string& day_week, int number) {

    std::string low_day;
    for (char c : day_week){
        low_day += std::tolower(c);
    }

    if (low_day == "понедельник" && number == 12) {
        return true;
    } else if (low_day == "вторник" && number > 95) {
        return true;
    } else if (low_day == "среда" && number == 34) {
        return true;
    } else if (low_day == "четверг" && number == 0) {
        return true;
    } else if (low_day == "пятница" && number % 2 == 0) {
        return true;
    } else if (low_day == "суббота" && number == 56) {
        return true;
    } else if (low_day == "воскресенье" && (number == 666 || number == -666)) {
        return true;
    }

    return false;
}