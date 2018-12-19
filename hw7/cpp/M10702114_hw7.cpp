#include <iostream>
#include <string>

using namespace std;

/*
	Class Archture
			Language
			/       \
		   /         \
		  / 	      \
	  Chinese     	  English
	  /		\      		/   └─────────────┐
Taiwanese    \	   Australian English     │
		Cantonese						American English
*/

class Language{
	/*
		預設建構函式
		拷貝建構函式
		拷貝指定運算子
		解構函式
		以及一稱為 print 之函式成員，其可將此類別所有的資料成員(包含繼承而來的)值
	*/
	public:
	string language_name;
	string whoismyroot = "Language";
	// 預設建構函式
	Language(){
		language_name = "Language";
	}

	// 帶有參數的函式
	Language(string lang){
		language_name = lang;
	}

	// 拷貝建構函式
	Language(const Language &other){
		this->language_name = other.language_name;
		
	}
	
	// 拷貝指定運算子
	Language &operator=(const Language &other) {
		if(this != &other) {
			this->language_name = other.language_name;
		}
		return *this;
	}

	// 解構函式
	~Language(void){
		cout << "Language is destroyed." << endl;
	}

	void print(void){
		cout << "My language name is " << language_name << "." << endl;
		cout << "My root is Class " << whoismyroot << "." << endl;
		cout << "-----------------------------------------" << endl;
	}
};

class Chinese : public Language{
	public:
	int using_people_number;
	// 預設建構函式
	Chinese():Language("Chinese"){
		using_people_number = 0;
	}

	// 帶有參數的函式
	Chinese(string lang):Language(lang){
		using_people_number = 0;	
	}
	Chinese(string lang, int number):Language(lang){
		using_people_number = number;
	}

	// 拷貝建構函式
	Chinese(const Chinese &other):Language(other){
		this->using_people_number = other.using_people_number;
	}
	
	// 拷貝指定運算子
	Chinese &operator=(const Chinese &other){
		if(this != &other) {
			this->language_name = other.language_name;
			this->using_people_number = other.using_people_number;
		}
		return *this;
	}

	// 解構函式
	~Chinese(void){
		cout << "Chinese is destroyed." << endl;
	}

	void print(void){
		cout << "My language name is " << language_name << "." << endl;
		cout << "My root is Class " << whoismyroot << "." << endl;
		cout << "Using people number is " << using_people_number << "." << endl;
		make_word();
		cout << "-----------------------------------------" << endl;
	}

	void make_word(){
		cout << "Make a chinese word." << endl;
	}
};

class Taiwanese : public Chinese{
	public:
	string using_country;
	// 預設建構函式
	Taiwanese():Chinese("Taiwanese"){
		using_country = "Taiwan";
	}

	// 帶有參數的函式
	Taiwanese(string lang):Chinese(lang, 0){
		using_country = "Taiwan";	
	}
	Taiwanese(string lang, int number):Chinese(lang, number){
		using_country = "Taiwan";
	}
	Taiwanese(string lang, int number, string country):Chinese(lang, number){
		using_country = country;
	}

	// 拷貝建構函式
	Taiwanese(const Taiwanese &other):Chinese(other){
		this->using_country = other.using_country;
	}
	
	// 拷貝指定運算子
	Taiwanese &operator=(const Taiwanese &other){
		if(this != &other) {
			this->language_name = other.language_name;
			this->using_people_number = other.using_people_number;
			this->using_country = other.using_country;
		}
		return *this;
	}

	// 解構函式
	~Taiwanese(void){
		cout << "Taiwanese is destroyed." << endl;
	}

	void print(void){
		cout << "My language name is " << language_name << "." << endl;
		cout << "My root is Class " << whoismyroot << "." << endl;
		cout << "Using people number is " << using_people_number << "." << endl;
		cout << "Using country is " << using_country << "." << endl;
		make_word();
		cout << "-----------------------------------------" << endl;
	}

	void make_word(){
		cout << "Make a chinese word by phonetic." << endl;
	}
};

class Cantonese : public Chinese{
	public:
	string using_country;
	// 預設建構函式
	Cantonese():Chinese("Cantonese"){
		using_country = "Hong Kong";
	}

	// 帶有參數的函式
	Cantonese(string lang):Chinese(lang, 0){
		using_country = "Hong Kong";	
	}
	Cantonese(string lang, int number):Chinese(lang, number){
		using_country = "Hong Kong";
	}
	Cantonese(string lang, int number, string country):Chinese(lang, number){
		using_country = country;
	}

	// 拷貝建構函式
	Cantonese(const Cantonese &other):Chinese(other){
		this->using_country = other.using_country;
	}
	
	// 拷貝指定運算子
	Cantonese &operator=(const Cantonese &other){
		if(this != &other) {
			this->language_name = other.language_name;
			this->using_people_number = other.using_people_number;
			this->using_country = other.using_country;
		}
		return *this;
	}

	// 解構函式
	~Cantonese(void){
		cout << "Cantonese is destroyed." << endl;
	}

	void print(void){
		cout << "My language name is " << language_name << "." << endl;
		cout << "My root is Class " << whoismyroot << "." << endl;
		cout << "Using people number is " << using_people_number << "." << endl;
		cout << "Using country is " << using_country << "." << endl;
		make_word();
		cout << "-----------------------------------------" << endl;
	}

	void make_word(){
		cout << "Make a chinese word by pinyin." << endl;
	}
};

class English : public Language{
	public:
	int using_people_number;
	// 預設建構函式
	English():Language("English"){
		using_people_number = 0;
	}

	// 帶有參數的函式
	English(string lang):Language(lang){
		using_people_number = 0;	
	}
	English(string lang, int number):Language(lang){
		using_people_number = number;
	}

	// 拷貝建構函式
	English(const English &other):Language(other){
		this->using_people_number = other.using_people_number;
	}
	
	// 拷貝指定運算子
	English &operator=(const English &other){
		if(this != &other) {
			this->language_name = other.language_name;
			this->using_people_number = other.using_people_number;
		}
		return *this;
	}

	// 解構函式
	~English(void){
		cout << "English is destroyed." << endl;
	}

	void print(void){
		cout << "My language name is " << language_name << "." << endl;
		cout << "My root is Class " << whoismyroot << "." << endl;
		cout << "Using people number is " << using_people_number << "." << endl;
		make_vocabulary();
		cout << "-----------------------------------------" << endl;
	}

	void make_vocabulary(){
		cout << "Make a Vocabulary." << endl;
	}
};

class AustralianEnglish : public English{
	public:
	string using_country;
	// 預設建構函式
	AustralianEnglish():English("Australian English"){
		using_country = "Australia";
	}

	// 帶有參數的函式
	AustralianEnglish(string lang):English(lang, 0){
		using_country = "Australia";	
	}
	AustralianEnglish(string lang, int number):English(lang, number){
		using_country = "Australia";
	}
	AustralianEnglish(string lang, int number, string country):English(lang, number){
		using_country = country;
	}

	// 拷貝建構函式
	AustralianEnglish(const AustralianEnglish &other):English(other){
		this->using_country = other.using_country;
	}
	
	// 拷貝指定運算子
	AustralianEnglish &operator=(const AustralianEnglish &other){
		if(this != &other) {
			this->language_name = other.language_name;
			this->using_people_number = other.using_people_number;
			this->using_country = other.using_country;
		}
		return *this;
	}

	// 解構函式
	~AustralianEnglish(void){
		cout << "AustralianEnglish is destroyed." << endl;
	}

	void print(void){
		cout << "My language name is " << language_name << "." << endl;
		cout << "My root is Class " << whoismyroot << "." << endl;
		cout << "Using people number is " << using_people_number << "." << endl;
		cout << "Using country is " << using_country << "." << endl;
		make_vocabulary();
		cout << "-----------------------------------------" << endl;
	}

	void make_vocabulary(){
		cout << "Make a Vocabulary for Australia." << endl;
	}
};

class AmericanEnglish : public English{
	public:
	string using_country;
	// 預設建構函式
	AmericanEnglish():English("American English"){
		using_country = "America";
	}

	// 帶有參數的函式
	AmericanEnglish(string lang):English(lang, 0){
		using_country = "America";	
	}
	AmericanEnglish(string lang, int number):English(lang, number){
		using_country = "America";
	}
	AmericanEnglish(string lang, int number, string country):English(lang, number){
		using_country = country;
	}

	// 拷貝建構函式
	AmericanEnglish(const AmericanEnglish &other):English(other){
		this->using_country = other.using_country;
	}
	
	// 拷貝指定運算子
	AmericanEnglish &operator=(const AmericanEnglish &other){
		if(this != &other) {
			this->language_name = other.language_name;
			this->using_people_number = other.using_people_number;
			this->using_country = other.using_country;
		}
		return *this;
	}

	// 解構函式
	~AmericanEnglish(void){
		cout << "AmericanEnglish is destroyed." << endl;
	}

	void print(void){
		cout << "My language name is " << language_name << "." << endl;
		cout << "My root is Class " << whoismyroot << "." << endl;
		cout << "Using people number is " << using_people_number << "." << endl;
		cout << "Using country is " << using_country << "." << endl;
		make_vocabulary();
		cout << "-----------------------------------------" << endl;
	}

	void make_vocabulary(){
		cout << "Make a Vocabulary for America." << endl;
	}
};

/*
	預設建構函式
	拷貝建構函式
	拷貝指定運算子
	解構函式
	以及一稱為 print 之函式成員，其可將此類別所有的資料成員(包含繼承而來的)值
*/
int main(){
	{
		cout << "Language Class:" << endl;
		cout << "\tDefault Constructor:" << endl;
		Language lang;
		lang.print();
		cout << "\tCopy Constructor:" << endl;
		lang.language_name = "Copy Language";
		Language copylang(lang);
		copylang.print();
		cout << "\tCopy Constructor Assignment Operator:" << endl;
		lang.language_name = "Copy Operator Language";
		copylang = lang;
		copylang.print();
		cout << "\tDestructor:" << endl;
	}
	cout << endl;
	{
		cout << "Chinese Class:" << endl;
		cout << "\tDefault Constructor:" << endl;
		Chinese lang;
		lang.print();
		cout << "\tCopy Constructor:" << endl;
		lang.language_name = "Copy Chinese";
		Chinese copylang(lang);
		copylang.print();
		cout << "\tCopy Constructor Assignment Operator:" << endl;
		lang.language_name = "Copy Operator Chinese";
		copylang = lang;
		copylang.print();
		cout << "\tDestructor:" << endl;
	}
	cout << endl;
	{
		cout << "Taiwanese Class:" << endl;
		cout << "\tDefault Constructor:" << endl;
		Taiwanese lang;
		lang.print();
		cout << "\tCopy Constructor:" << endl;
		lang.language_name = "Copy Taiwanese";
		Taiwanese copylang(lang);
		copylang.print();
		cout << "\tCopy Constructor Assignment Operator:" << endl;
		lang.language_name = "Copy Operator Taiwanese";
		copylang = lang;
		copylang.print();
		cout << "\tDestructor:" << endl;
	}
	cout << endl;
	{
		cout << "Cantonese Class:" << endl;
		cout << "\tDefault Constructor:" << endl;
		Cantonese lang;
		lang.print();
		cout << "\tCopy Constructor:" << endl;
		lang.language_name = "Copy Cantonese";
		Cantonese copylang(lang);
		copylang.print();
		cout << "\tCopy Constructor Assignment Operator:" << endl;
		lang.language_name = "Copy Operator Cantonese";
		copylang = lang;
		copylang.print();
		cout << "\tDestructor:" << endl;
	}
	cout << endl;
	{
		cout << "English Class:" << endl;
		cout << "\tDefault Constructor:" << endl;
		English lang;
		lang.print();
		cout << "\tCopy Constructor:" << endl;
		lang.language_name = "Copy English";
		English copylang(lang);
		copylang.print();
		cout << "\tCopy Constructor Assignment Operator:" << endl;
		lang.language_name = "Copy Operator English";
		copylang = lang;
		copylang.print();
		cout << "\tDestructor:" << endl;
	}
	cout << endl;
	{
		cout << "AustralianEnglish Class:" << endl;
		cout << "\tDefault Constructor:" << endl;
		AustralianEnglish lang;
		lang.print();
		cout << "\tCopy Constructor:" << endl;
		lang.language_name = "Copy AustralianEnglish";
		AustralianEnglish copylang(lang);
		copylang.print();
		cout << "\tCopy Constructor Assignment Operator:" << endl;
		lang.language_name = "Copy Operator AustralianEnglish";
		copylang = lang;
		copylang.print();
		cout << "\tDestructor:" << endl;
	}
	cout << endl;
	{
		cout << "AmericanEnglish Class:" << endl;
		cout << "\tDefault Constructor:" << endl;
		AmericanEnglish lang;
		lang.print();
		cout << "\tCopy Constructor:" << endl;
		lang.language_name = "Copy AmericanEnglish";
		AmericanEnglish copylang(lang);
		copylang.print();
		cout << "\tCopy Constructor Assignment Operator:" << endl;
		lang.language_name = "Copy Operator AmericanEnglish";
		copylang = lang;
		copylang.print();
		cout << "\tDestructor:" << endl;
	}


	/*
	Chinese chin;
	chin.print();
	English eng("English");
	eng.print();
	Taiwanese tai("Taiwanese", 2300, "Taiwan");
	tai.print();
	Cantonese can;
	can.print();
	Cantonese copycan("Taiwanese", 2300, "Taiwan");
	copycan.print();
	can = copycan;
	can.print();
	*/
	system("pause");
	return 0;
}