#include <QtCore>
#include <QtTest>

#include "../../include/Ressources.hpp"

#include "../../include/tools/Log.hpp"

#include <cstring>
#include <fstream>

/*
        This file is testing the ressources management by providing and testing a string ressource manager
*/


// ressource based on std::string
struct StringRessource : public se::Ressource<std::string> {

    StringRessource(const std::string &url, se::DELETE_TYPE del) : se::Ressource<std::string>(del) {
        m_data = new std::string(url);  // here you can load some file for example
    }

    // a default destructor is define in se::Ressource

};


// and here come our string manager
struct StringManager : public se::RessourceManager<StringRessource> {

    // there is nothing to override here ...
};


class RessourceTests : public QObject {

Q_OBJECT

private :
    StringManager *sm;

    std::ofstream *m_logFile;

public :

    RessourceTests() {

        m_logFile = new std::ofstream("logs.txt");
        Log::setOutput(*m_logFile);

        Log::v() << "-- Ressources demo & test --";

        sm = new StringManager();
        sm->loadRessource("never_delete_me", se::NEVER_DELETE);
        sm->loadRessource("do_not_delete_me", se::DO_NOT_DELETE);
        sm->loadRessource("auto_delete", se::AUTO_DELETE);      // AUTO_DELETE is optionnal
    }


    ~RessourceTests() {
        delete sm;
        m_logFile->close();
        delete m_logFile;
    }


private slots:

    /*
        This ressource does not exists
    */
    void ressourceIsNotLoaded() {

        // at the begining, the ressource isn't load
        QVERIFY( ! sm->isLoaded("temp_ressource") );

        // this will load the ressource
        const std::string *fr = sm->getRessource("temp_ressource");
        const std::string *fr2 = sm->getRessource("temp_ressource");
        std::cout << "fr & fr2 content : " << *fr << " , " << *fr2 << std::endl;

        // the ressource is now loaded
        QVERIFY( sm->isLoaded("temp_ressource") );

        // release one time
        sm->releaseRessource("temp_ressource");

        // the ressource stay loaded in memory
        QVERIFY( sm->isLoaded("temp_ressource") );

        // release one more time
        sm->releaseRessource("temp_ressource");

        // now the ressource should be freed
        QVERIFY( ! sm->isLoaded("temp_ressource") );
    }


    /*
        Now let's play with the auto_delete
    */
    void testAutoDelete() {

        // the ressource has been loaded in constructor
        QVERIFY( sm->isLoaded("auto_delete") );

        const std::string *sr = sm->getRessource("auto_delete");
        std::cout << "sr content : " << *sr << std::endl;

        // release ...
        sm->releaseRessource("auto_delete");

        // should not stay in memory
        QVERIFY( ! sm->isLoaded("auto_delete") );
    }


    /*
        Test "DO_NOT_DELETE"
    */
    void testDoNotDelete() {

        // the ressource has been loaded in constructor
        QVERIFY( sm->isLoaded("do_not_delete_me") );

        // we tell to manager that we want to delete all loaded ressources !
        sm->deleteAllRessources();

        // should not stay in memory
        QVERIFY( ! sm->isLoaded("do_not_delete_me") );
    }


    /*
        Test "NEVER_DELETE"
    */
    void testNeverDelete() {

        // the previous test has deleted all loaded ressources
        // BUT our ressource is tagged "NEVER_DELETE"
        // so it sould be load
        QVERIFY( sm->isLoaded("never_delete_me") );

        // we can force ressource deleting
        sm->forceDeleteAllRessouces();

        // ressource should be deleted
        QVERIFY( ! sm->isLoaded("never_delete_me") );

    }


    /*
        Beware !
    */
    void oneMoreTest() {

        const std::string *tr1 = sm->getRessource("test_ressource");
        const std::string *tr2 = sm->getRessource("test_ressource");

        // ... You don't need tr1 again, you have to use release !
        // If you decide to delete it yourself, keep thinking
        // that other part of your program could use this ressource
        // for example, imagine you don't need tr1 again

        sm->deleteRessource("test_ressource");

        // so the ressource is now freed
        QVERIFY( ! sm->isLoaded("test_ressource") );

        // but ... what's about tr2 ? You don't really know !


        // you can notice that releasing an unloaded ressource is
        // creating a warning in the application log
        sm->releaseRessource("unloaded_ressource");
    }

};


QTEST_MAIN(RessourceTests)


