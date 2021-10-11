# AutoCache
AutoCache/GtCache

## usage:
 - firstly "gtcache.exe" and "proxy.exe" must same path "server.exe"
 - after we goto main void
```cpp
cache/*or whatever source use cache string*/ = takecache("GrowID", "Password");
```

```cpp
string gtcache = "";
string takecache(string GrowID, string Password)
{
	try
	{
		std::string line;
		std::string readline;
		std::ifstream myfile("lastcache.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				readline += line;
			}
			myfile.close();
		}
		std::string::size_type sz;
		int code = std::stoi(readline.substr(6), &sz);
		std::ofstream myfilep;
		myfilep.open("acc.txt");
		myfilep << GrowID + "." + Password;
		myfilep.close();
		system("start proxy.exe");
		bool okey = true;
		cout << "finding cache..." << endl;
		while (okey)
		{
			std::string line;
			std::string readline;
			std::ifstream myfile("lastcache.txt");
			if (myfile.is_open())
			{
				while (getline(myfile, line))
				{
					readline += line;
				}
				myfile.close();
			}
			std::string::size_type sz;
			int codes = std::stoi(readline.substr(6), &sz);
			if (code != codes)
			{
				gtcache = readline.substr(0, 5);
				okey = false;
				return readline.substr(0, 5);
			}
		}
	}
	catch (const std::exception&)
	{
		std::ofstream myfile;
		myfile.open("lastcache.txt");
		myfile << "00000/0";
		myfile.close();
		cout << "Restart Server!\n";
		system("pause");
	}
}
```

![1](https://user-images.githubusercontent.com/77299279/136859996-66b30cae-a615-4068-8470-9d34083b6560.PNG)




![2](https://user-images.githubusercontent.com/77299279/136860016-662b43fc-c204-4fc1-a44d-20527f189a99.PNG)
