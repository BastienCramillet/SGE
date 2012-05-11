#include <QtCore>
#include <QtTest>


#include "../../include/tools/Log.hpp"

#include <cstring>
#include <fstream>


const std::string pre_path = "../ressource_files_test/files/";


/*

*/


class RessourceFileTests : public QObject {

Q_OBJECT

private :

    std::ofstream *m_logFile;


public :

    RessourceFileTests() {

        m_logFile = new std::ofstream("logs.txt");
        Log::setOutput(*m_logFile);

        Log::v() << "-- Ressources files demo & test --";
    }


    ~RessourceFileTests() {
        m_logFile->close();
        delete m_logFile;
    }


private slots:

    /*

    */
    void test() {
        QVERIFY( TRUE );
    }


};


QTEST_MAIN(RessourceFileTests)


