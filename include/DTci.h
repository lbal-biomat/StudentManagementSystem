//
// Created by lucia on 31/3/22.
//

#ifndef SISTEMABEDELIA_DTCI_H
#define SISTEMABEDELIA_DTCI_H

#include <string>


class DTci {
  private:
    int ci;
  public:
    DTci(int);
    int getCInumber() const;
    static bool validate(const std::string & ci);
    bool operator==(DTci) const;
    bool operator==(int) const;
};



#endif //SISTEMABEDELIA_DTCI_H
