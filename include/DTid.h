//
// Created by lucia on 31/3/22.
//

#ifndef SISTEMABEDELIA_DTID_H
#define SISTEMABEDELIA_DTID_H

#include <string>


class DTid {
  private:
    int ci;
  public:
    DTid(const std::string & ci);
    DTid(int ci);
    int getIDnumber() const;
    static bool validate(int ci);
    bool operator==(DTid) const;
    bool operator==(int) const;
};



#endif //SISTEMABEDELIA_DTID_H
