## Homework 6
# 作業說明
* hw6.doc
* 請為hw6.cpp補上程式，使得hw6.cpp之主程式可以順利執行。
* 程式要求：
	1.	主程式中之程式不可更改。
	2.	將您作業四中所定義的matrix類別，加入到主程式前。
	3.	仿照您於作業四所定義的matrix類別，新定義vector類別，並同樣將其加到主程式前。
	4.	提供MmultV 與 VmultM兩函式，其同時為matrix與vector之朋友函式，其內容需直接存取所傳入matrix與vector物件的私有成員，來計算兩物件相乘的結果，最後將結果以傳參考的方式傳回。
	5.	對於matrix與vector類別，分別各新增一稱為count之私有靜態成員(private static member)，其值用來追蹤程式執行時所存在的matrix或vector物件數目，需隨物件之產生或釋放而改變。
	6.	對於matrix與vector類別，提供稱為getCount之靜態函式成員(static function member)，用來讀取count值，得知現存之物件數目。
* 本作業之繳交格式為:
	* 於課堂上繳交列印之程式碼，並將程式碼檔案email給助教。
# 作業檔案
* cpp/M10702114_hw6.cpp