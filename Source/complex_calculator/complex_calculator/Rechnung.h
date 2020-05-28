#pragma once
template <typename T>
class Rechnung
{
private:
	T zahl1;
	T zahl2;
	T ergebnis;
public:
	Rechnung();
	~Rechnung();

	T &getZahl1(); //! Gibt die Zahl 1 zur�ck
	T &getZahl2(); //! Gibt die Zahl 2 zur�ck
	T &getErgebnis(); //! Gibt das Ergebnis zur�ck
	void setZahl1(const T &Zahl);
	void setZahl2(const T &Zahl);

	void addieren();
	void subtrahieren();
	void multiplizieren();
	void dividieren();
};