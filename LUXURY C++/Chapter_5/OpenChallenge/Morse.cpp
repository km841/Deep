#include "Morse.h"

Morse::Morse()
{
	string alphabet[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
	".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-", "-.--", "--.." };

	string digit[10] = { "-----", ".----", "..---", "...--", "....-",
		".....", "-....", "--...", "----..", "----." };

	slash = "-..-.";
	question = "..--..";
	comma = ".-.-.-";
	period = "--..--";
	plus = ".-.-.";
	equal = "-...-";

	for (int i = 0; i < 26; i++)
	{
		t2m[string(1, (char)i + 97)] = alphabet[i];
		m2t[alphabet[i]] = string(1, (char)i + 97);
	}

	for (int i = 0; i < 10; i++)
	{
		t2m[to_string(i)] = digit[i];
		m2t[digit[i]] = to_string(i);
	}

	t2m["/"] = slash;
	m2t[slash] = "/";

	t2m["?"] = question;
	m2t[question] = "?";

	t2m["."] = comma;
	m2t[comma] = ".";

	t2m[","] = period;
	m2t[period] = ",";

	t2m["+"] = plus;
	m2t[plus] = "+";

	t2m["="] = equal;
	m2t[equal] = "=";

	m2t["   "] = " ";
}
void Morse::text2Morse(string text, string& morse)
{
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == ' ')
		{
			morse += "   ";
			continue;
		}

		morse += t2m[string(1, text[i])];
		morse += " ";
	}
}

bool Morse::morse2Test(string morse, string& text)
{
	int prev = 0;
	int curr = morse.find(" ", prev);

	while (curr != string::npos)
	{
		if (morse[curr + 1] == ' ' && morse[curr + 2] == ' ')
		{
			text += " ";
			prev = curr + 3;
			curr = morse.find(' ', prev);
			continue;
		}

		text += m2t[morse.substr(prev, curr - prev)];
		prev = curr + 1;
		curr = morse.find(' ', prev);
	}

	text += m2t[morse.substr(prev)];
	return true;
}
