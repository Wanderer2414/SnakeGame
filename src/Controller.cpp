#include "../include/Controller.h"

Controller::Controller(const int& index):m_index(index) {

}
int Controller::getIndex() const {
    return m_index;
}