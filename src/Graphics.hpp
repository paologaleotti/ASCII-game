class MainWindow {
private:
	char wallCh;
	char playerCh;
	char enemyCh;

	char matrixTranslate(int toConvert);

public:
	int currentRoom[10][10];
	MainWindow(char wallch, char playerch, char enemych);
    void printRoom(int room[][10]);
};