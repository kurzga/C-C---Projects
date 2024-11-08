#include <iostream>
#include <locale.h>
#include <ctime>
#include <string>
using namespace std;

class Demographics_Geographics {
protected:
    int Age, Income, Home_owner; // Yaş, Gelir, Ev sahibi (Ör: 1 Ev Sahibi, 0 Kiracı)
    wstring Socio_Economic_Status, Geographic_Factors, Gender, Ethnicity, Religion, Education; // Sosyo-Ekonomik Durum, Coğrafi Faktörler, Cinsiyet, Etnik Köken, Din, Eğitim

public:
    Demographics_Geographics() {
        Age = Income = Home_owner = 0;
        Socio_Economic_Status = Geographic_Factors = Gender = Ethnicity = Religion = Education = L" ";
    }

    // Get yöntemleri
    int getAge() const { return Age; }
    int getIncome() const { return Income; }
    int getHomeOwner() const { return Home_owner; }
    wstring getSocioEconomicStatus() const { return Socio_Economic_Status; }
    wstring getGeographicFactors() const { return Geographic_Factors; }
    wstring getGender() const { return Gender; }
    wstring getEthnicity() const { return Ethnicity; }
    wstring getReligion() const { return Religion; }
    wstring getEducation() const { return Education; }

    // Set yöntemleri
    void setAge(int age) { Age = age; }
    void setIncome(int income) { Income = income; }
    void setHomeOwner(int homeowner) { Home_owner = homeowner; }
    void setSocioEconomicStatus(const wstring& status) { Socio_Economic_Status = status; }
    void setGeographicFactors(const wstring& factors) { Geographic_Factors = factors; }
    void setGender(const wstring& gender) { Gender = gender; }
    void setEthnicity(const wstring& ethnicity) { Ethnicity = ethnicity; }
    void setReligion(const wstring& religion) { Religion = religion; }
    void setEducation(const wstring& education) { Education = education; }
};

class Personality {
protected:
    int Reciprocity, Scarcity, Authority, Social_Proof; // Karşılıklılık, Az Bulunurluk, Otorite, Sosyal Kanıt
    int Openness, Conscientiousness, Extraversion, agreeableness, neuroticism; // Açıklık, Bilinçlilik, Dışadönüklük, Uyum, Nörotisizm
    wstring Fear;
public:
    Personality() {
        Reciprocity = Scarcity = Authority = Social_Proof = Openness = Conscientiousness = Extraversion = agreeableness = neuroticism = 0;
        Fear = L" "; 
    }

    // Get yöntemleri
    int getReciprocity() const { return Reciprocity; }
    int getScarcity() const { return Scarcity; }
    int getAuthority() const { return Authority; }
    wstring getFear() const { return Fear; }
    int getSocialProof() const { return Social_Proof; }
    int getOpenness() const { return Openness; }
    int getConscientiousness() const { return Conscientiousness; }
    int getExtraversion() const { return Extraversion; }
    int getAgreeableness() const { return agreeableness; }
    int getNeuroticism() const { return neuroticism; }

    // Set yöntemleri
    void setReciprocity(int value) { Reciprocity = value; }
    void setScarcity(int value) { Scarcity = value; }
    void setAuthority(int value) { Authority = value; }
    void setFear(const wstring& value) { Fear = value; }
    void setSocialProof(int value) { Social_Proof = value; }
    void setOpenness(int value) { Openness = value; }
    void setConscientiousness(int value) { Conscientiousness = value; }
    void setExtraversion(int value) { Extraversion = value; }
    void setAgreeableness(int value) { agreeableness = value; }
    void setNeuroticism(int value) { neuroticism = value; }
};

class Psychographics {
protected:
    int Advertising_Dissonance, Automotive_Data, consumer_confidence_economy_business, Civic, Cellular; // Reklam Tutarsızlığı, Otomatik Veri, Tüketici Güveni, Yurttaşlık, Hücresel
    wstring Buying_Styles_Patterns, Consumer_Data, Lifestyle_Data; // Satın Alma Modelleri,Tüketici Verileri, Yaşam Tarzı Verileri

public:
    Psychographics() {
        Advertising_Dissonance = Automotive_Data = consumer_confidence_economy_business = Civic = 0;
        Consumer_Data = Lifestyle_Data = Buying_Styles_Patterns = L" ";
    }

    // Get yöntemleri
    int getAdvertisingDissonance() const { return Advertising_Dissonance; }
    int getAutomotiveData() const { return Automotive_Data; }
    int getConsumerConfidenceEconomyBusiness() const { return consumer_confidence_economy_business; }
    int getCivic() const { return Civic; }
    wstring getConsumerData() const { return Consumer_Data; }
    wstring getLifestyleData() const { return Lifestyle_Data; }
    wstring getBuyingStylesPatterns() const { return Buying_Styles_Patterns; }

    // Set yöntemleri
    void setAdvertisingDissonance(int value) { Advertising_Dissonance = value; }
    void setAutomotiveData(int value) { Automotive_Data = value; }
    void setConsumerConfidenceEconomyBusiness(int value) { consumer_confidence_economy_business = value; }
    void setBuyingStylesPatterns(const wstring& value) { Buying_Styles_Patterns = value; }
    void setCivic(int value) { Civic = value; }
    void setConsumerData(const wstring& data) { Consumer_Data = data; }
    void setLifestyleData(const wstring& data) { Lifestyle_Data = data; }
};

class Person : protected Demographics_Geographics, Personality, Psychographics {
private:
    int ID;

public:
    Person() {
    	ID = 0;
    }

    // Get yöntemleri
    int getID() const { return ID; }
    int getAge() const { return Demographics_Geographics::getAge(); }
    int getIncome() const { return Demographics_Geographics::getIncome(); }
    int getHomeOwner() const { return Demographics_Geographics::getHomeOwner(); }
    wstring getSocioEconomicStatus() const { return Demographics_Geographics::getSocioEconomicStatus(); }
    wstring getGeographicFactors() const { return Demographics_Geographics::getGeographicFactors(); }
    wstring getGender() const { return Demographics_Geographics::getGender(); }
    wstring getEthnicity() const { return Demographics_Geographics::getEthnicity(); }
    wstring getReligion() const { return Demographics_Geographics::getReligion(); }
    wstring getEducation() const { return Demographics_Geographics::getEducation(); }
    wstring getFear() const { return Personality::getFear(); }

    int getReciprocity() const { return Personality::getReciprocity(); }
    int getScarcity() const { return Personality::getScarcity(); }
    int getAuthority() const { return Personality::getAuthority(); }
    int getSocialProof() const { return Personality::getSocialProof(); }
    int getOpenness() const { return Personality::getOpenness(); }
    int getConscientiousness() const { return Personality::getConscientiousness(); }
    int getExtraversion() const { return Personality::getExtraversion(); }
    int getAgreeableness() const { return Personality::getAgreeableness(); }
    int getNeuroticism() const { return Personality::getNeuroticism(); }

    int getAdvertisingDissonance() const { return Psychographics::getAdvertisingDissonance(); }
    int getAutomotiveData() const { return Psychographics::getAutomotiveData(); }
    int getConsumerConfidenceEconomyBusiness() const { return Psychographics::getConsumerConfidenceEconomyBusiness(); }
    int getCivic() const { return Psychographics::getCivic(); }
    wstring getConsumerData() const { return Psychographics::getConsumerData(); }
    wstring getLifestyleData() const { return Psychographics::getLifestyleData(); }
    wstring getBuyingStylesPatterns() const { return Psychographics::getBuyingStylesPatterns(); }

    // Set yöntemleri
    void setID(int id) { ID = id; }
    void setAge(int age) { Demographics_Geographics::setAge(age); }
    void setIncome(int income) { Demographics_Geographics::setIncome(income); }
    void setHomeOwner(int homeowner) { Demographics_Geographics::setHomeOwner(homeowner); }
    void setSocioEconomicStatus(const wstring& status) { Demographics_Geographics::setSocioEconomicStatus(status); }
    void setGeographicFactors(const wstring& factors) { Demographics_Geographics::setGeographicFactors(factors); }
    void setGender(const wstring& gender) { Demographics_Geographics::setGender(gender); }
    void setEthnicity(const wstring& ethnicity) { Demographics_Geographics::setEthnicity(ethnicity); }
    void setReligion(const wstring& religion) { Demographics_Geographics::setReligion(religion); }
    void setEducation(const wstring& education) { Demographics_Geographics::setEducation(education); }

    void setReciprocity(int value) { Personality::setReciprocity(value); }
    void setScarcity(int value) { Personality::setScarcity(value); }
    void setAuthority(int value) { Personality::setAuthority(value); }
    void setFear(const wstring& value) { Personality::setFear(value); }
    void setSocialProof(int value) { Personality::setSocialProof(value); }
    void setOpenness(int value) { Personality::setOpenness(value); }
    void setConscientiousness(int value) { Personality::setConscientiousness(value); }
    void setExtraversion(int value) { Personality::setExtraversion(value); }
    void setAgreeableness(int value) { Personality::setAgreeableness(value); }
    void setNeuroticism(int value) { Personality::setNeuroticism(value); }

    void setAdvertisingDissonance(int value) { Psychographics::setAdvertisingDissonance(value); }
    void setAutomotiveData(int value) { Psychographics::setAutomotiveData(value); }
    void setConsumerConfidenceEconomyBusiness(int value) { Psychographics::setConsumerConfidenceEconomyBusiness(value); }
    void setBuyingStylesPatterns(const wstring& value) { Psychographics::setBuyingStylesPatterns(value); }
    void setCivic(int value) { Psychographics::setCivic(value); }
    void setConsumerData(const wstring& data) { Psychographics::setConsumerData(data); }
    void setLifestyleData(const wstring& data) { Psychographics::setLifestyleData(data); }
};

void printPersonData(const Person& person) {
    wcout << L"Kişi Verileri:\n";
    wcout << L"ID: " << person.getID() << endl;
    wcout << L"Yaş: " << person.getAge() << endl;
    wcout << L"Gelir: " << person.getIncome() << endl;
    wcout << L"Ev Sahibi: " << (person.getHomeOwner() ? L"Evet" : L"Hayır") << endl;
    wcout << L"Sosyo-Ekonomik Durum: " << person.getSocioEconomicStatus() << endl;
    wcout << L"Coğrafi Faktörler: " << person.getGeographicFactors() << endl;
    wcout << L"Cinsiyet: " << person.getGender() << endl;
    wcout << L"Etnik Köken: " << person.getEthnicity() << endl;
    wcout << L"Din: " << person.getReligion() << endl;
    wcout << L"Eğitim: " << person.getEducation() << endl;
    wcout << L"Karşılıklılık: " << person.getReciprocity() << endl;
    wcout << L"Az Bulunurluk: " << person.getScarcity() << endl;
    wcout << L"Otorite: " << person.getAuthority() << endl;
    wcout << L"Korku: " << person.getFear() << endl;
    wcout << L"Sosyal Kanıt: " << person.getSocialProof() << endl;
    wcout << L"Açıklık: " << person.getOpenness() << endl;
    wcout << L"Bilinçlilik: " << person.getConscientiousness() << endl;
    wcout << L"Dışadönüklük: " << person.getExtraversion() << endl;
    wcout << L"Uyum: " << person.getAgreeableness() << endl;
    wcout << L"Nörotisizm: " << person.getNeuroticism() << endl;
    wcout << L"Reklam Tutarsızlığı: " << person.getAdvertisingDissonance() << endl;
    wcout << L"Otomatik Veri: " << person.getAutomotiveData() << endl;
    wcout << L"Tüketici Güveni: " << person.getConsumerConfidenceEconomyBusiness() << endl;
    wcout << L"Yurttaşlık: " << person.getCivic() << endl;
    wcout << L"Tüketici Verileri: " << person.getConsumerData() << endl;
    wcout << L"Yaşam Tarzı Verileri: " << person.getLifestyleData() << endl;
    wcout << L"Satın Alma Modelleri: " << person.getBuyingStylesPatterns() << endl;
    wcout << endl;
}

int main() {
    setlocale(LC_ALL, "Turkish");
    srand(time(0));
    
    Person Ahmet,Mahmut;
    Ahmet.setID(rand());
    Ahmet.setAdvertisingDissonance(3);
    Ahmet.setAge(60);
    Ahmet.setAgreeableness(1);
    Ahmet.setAuthority(7);
    Ahmet.setAutomotiveData(0);
    Ahmet.setBuyingStylesPatterns(L"manav,market,bakkal");
    Ahmet.setCivic(2);
    Ahmet.setConscientiousness(4);
    Ahmet.setConsumerConfidenceEconomyBusiness(8);
    Ahmet.setConsumerData(L"Pahalıysa alma");
    Ahmet.setEducation(L"İlkokul terk");
    Ahmet.setEthnicity(L"Türk");
    Ahmet.setExtraversion(7);
    Ahmet.setFear(L"Terörism");
    Ahmet.setGender(L"erkek");
    Ahmet.setGeographicFactors(L"iç anadolu");
    Ahmet.setHomeOwner(1);
    Ahmet.setIncome(7500);
    Ahmet.setLifestyleData(L"sağlıksız,rutin");
    Ahmet.setNeuroticism(3);
    Ahmet.setOpenness(0);
    Ahmet.setReciprocity(1);
    Ahmet.setReligion(L"islam");
    Ahmet.setScarcity(0);
    Ahmet.setSocialProof(0);
    Ahmet.setSocioEconomicStatus(L"E:Altın Altı Kalifiye olmayan işçiler, vücutları ile çalışanlar (tarım işçileri, hamallar vb.), küçük esnaflar ve işsizlerden oluşmaktadır. Gelir ve eğitim seviyesi en düşük olan gruptur.");

    printPersonData(Ahmet);

    return 0;
}
