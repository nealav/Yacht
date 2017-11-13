#include <iostream>
#include <cstdlib>
#include <ctime> //for rand-seeding
#include <string> //string usage
#include <sstream> //sort-function stoi conversion
#include <iomanip> //for different cin.() functions


using namespace std;


int Die1, Die2, Die3, Die4, Die5; //dice values
int rrD1, rrD2, rrD3, rrD4, rrD5; //temporary integers for dice re-roll storage
int Round1, Round2, Round3, Round4, Round5, Round6, Round7, Round8, Round9, Round10, Round11, Round12; //round scores
int roundCounter = 0, diceReRollCounter = 0; //used to determine which round it is
int totalScore, roundScore = 0; //total score and temp integer to hold and transfer each round score
int gameChoice, roundChoice; //console input player choices
bool Ones = false, Twos = false, Threes = false, Fours = false, Fives = false, Sixes = false, Full_House = false, Four_Of_A_Kind = false, Little_Straight = false, Big_Straight = false, Choice = false, Yacht = false; //game-state truth values of each category


void roundMenu () //displays the different round scores at the end of each game
{
    totalScore = Round1 + Round2 + Round3 + Round4 + Round5 + Round6 + Round7 + Round8 + Round9 + Round10 + Round11 + Round12;
    cout << "\nINDIVIDUAL ROUND SCORES" << endl;
    cout << "Round 1: " << setw(6) << Round1 << endl;
    cout << "Round 2: " << setw(6) << Round2 << endl;
    cout << "Round 3: " << setw(6) << Round3 << endl;
    cout << "Round 4: " << setw(6) << Round4 << endl;
    cout << "Round 5: " << setw(6) << Round5 << endl;
    cout << "Round 6: " << setw(6) << Round6 << endl;
    cout << "Round 7: " << setw(6) << Round7 << endl;
    cout << "Round 8: " << setw(6) << Round8 << endl;
    cout << "Round 9: " << setw(6) << Round9 << endl;
    cout << "Round 10: " << setw(5) << Round10 << endl;
    cout << "Round 11: " << setw(5) << Round11 << endl;
    cout << "Round 12: " << setw(5) << Round12 << endl;
    cout << "Total Score: " << setw(2) << totalScore << endl;

}

void diceView () //outputs to console dice values
{
    cout << "Die 1: " << Die1 << endl;
    cout << "Die 2: " << Die2 << endl;
    cout << "Die 3: " << Die3 << endl;
    cout << "Die 4: " << Die4 << endl;
    cout << "Die 5: " << Die5 << endl;
}

void diceRoll (int& D1, int& D2, int& D3, int& D4, int& D5) //rolls the dice using pass-by-reference and generates different dice values based on Time
{
    srand(time(NULL)); //seed the rand() using Time
    D1 = rand() % 6 + 1;
    D2 = rand() % 6 + 1;
    D3 = rand() % 6 + 1;
    D4 = rand() % 6 + 1;
    D5 = rand() % 6 + 1;

}

void roundScoring(int& rCounter, int rScore) //game-state function used to score the round using a counter, roll the dice for the next round and reset dice counter value
{
    if (rCounter == 1) {
        Round1 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 2) {
        Round2 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 3) {
        Round3 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 4) {
        Round4 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 5) {
        Round5 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 6) {
        Round6 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 7) {
        Round7 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 8) {
        Round8 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 9) {
        Round9 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 10) {
        Round10 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 11) {
        Round11 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
    else if (rCounter == 12) {
        Round12 = rScore;
        rCounter++;
        diceReRollCounter = 0;
        diceRoll(Die1, Die2, Die3, Die4, Die5);
    }
}

void sortDice (int& D1, int& D2, int& D3, int& D4, int& D5) //an ascending sorting function using pass-by-reference to arrange the dice, does not use arrays
{

    //There are two ways I've found to sort the integer values without an array. One uses a Sorting Network derived from Batcher's Odd-Even Mergesort. The other is a more simplistic solution
    //that uses a divide-by-10 algorithm of O(n) efficiency. A third option I've come across is using a rudimentary merge sort that consecutively swaps numbers. Obviously the max swap limit must
    //be calculated for each "level" but I've assumed that limit to be (n-1)! or 5!

    /*
    string number = '12345'
    stringstream convert(number);
    convert >> numbertoSort;
    int sortedNumber = 0;
        for (int i = 9; i >= 0; i--)
            {
                int tmpNumber = numbertoSort;
                while (tmpNumber > 0)
                    {
                        int digit = tmpNumber % 10;
                        if (digit == i)
                            {
                                sortedNumber *= 10;
                                sortedNumber += digit;
                            }
                        tmpNumber /= 10;
                    }
            }
    cout << sortedNumber << endl;
    */ //I've included this divide-by-10 algorithm that works for numbers larger than 5. I could not get it to read the dice, however manually input numbers will always read with O(n) efficency.
    //You can make the above code work simply by uncommenting it and trying it out.

    int tmp;
    for (int i = 0; i < 120; i++) {
        if (D1 > D2) {tmp = D1; D1 = D2; D2 = tmp;}
        if (D2 > D3) {tmp = D2; D2 = D3; D3 = tmp;}
        if (D3 > D4) {tmp = D3; D3 = D4; D4 = tmp;}
        if (D4 > D5) {tmp = D4; D4 = D5; D5 = tmp;}
    }
}

void evaluatesOnes (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Ones category score
{

            if (D1 == 1) {
                roundScore += D1;
            }
            else if (D2 == 1) {
                roundScore += D2;
            }
            else if (D3 == 1) {
                roundScore += D3;
            }
            else if (D4 == 1) {
                roundScore += D4;
            }
            else if (D5 == 1) {
                roundScore += D5;
            }
            else {
                roundScore += 0;
            }
            Ones = true;
}

void evaluateTwos (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Twos category score
{

            if (D1 == 2) {
                roundScore += D1;
            }
            else if (D2 == 2) {
                roundScore += D2;
            }
            else if (D3 == 2) {
                roundScore += D3;
            }
            else if (D4 == 2) {
                roundScore += D4;
            }
            else if (D5 == 2) {
                roundScore += D5;
            }
            else {
                roundScore += 0;
            }
            Twos = true;
}

void evaluateThrees (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Threes category score
{

            if (D1 == 3) {
                roundScore += D1;
            }
            else if (D2 == 3) {
                roundScore += D2;
            }
            else if (D3 == 3) {
                roundScore += D3;
            }
            else if (D4 == 3) {
                roundScore += D4;
            }
            else if (D5 == 3) {
                roundScore += D5;
            }
            else {
                roundScore += 0;
            }
            Threes = true;
}

void evaluateFours (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Fours category score
{

            if (D1 == 4) {
                roundScore += D1;
            }
            else if (D2 == 4) {
                roundScore += D2;
            }
            else if (D3 == 4) {
                roundScore += D3;
            }
            else if (D4 == 4) {
                roundScore += D4;
            }
            else if (D5 == 4) {
                roundScore += D5;
            }
            else {
                roundScore += 0;
            }
            Fours = true;
}

void evaluateFives (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Fives category score
{

            if (D1 == 5) {
                roundScore += D1;
            }
            else if (D2 == 5) {
                roundScore += D2;
            }
            else if (D3 == 5) {
                roundScore += D3;
            }
            else if (D4 == 5) {
                roundScore += D4;
            }
            else if (D5 == 5) {
                roundScore += D5;
            }
            else {
                roundScore += 0;
            }
            Fives = true;
}

void evaluateSixes (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Sixes category score
{

            if (D1 == 6) {
                roundScore += D1;
            }
            else if (D2 == 6) {
                roundScore += D2;
            }
            else if (D3 == 6) {
                roundScore += D3;
            }
            else if (D4 == 6) {
                roundScore += D4;
            }
            else if (D5 == 6) {
                roundScore += D5;
            }
            else {
                roundScore += 0;
            }
            Sixes = true;
}

void evaluateFullHouse (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Full House category score
{

    if ((D1 == D2 && D2 == D3 && D4 == D5) || (D1 == D2 && D3 == D4 && D4 == D5)) {
        roundScore = D1+D2+D3+D4+D5;
    }
    else {
        roundScore = 0;
    }
    Full_House = true;
}

void evaluateFourOfAKind (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Four-of-a-kind category score
{

    if ((D1 == D2 && D2 == D3 && D3 == D4) || (D2 == D3 && D3 == D4 && D4 == D5) ) {
        roundScore = D3*4;
    }
    else {
        roundScore = 0;
    }
    Four_Of_A_Kind = true;
}

void evaluateLittleStraight (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Little Straight category score
{

    if (D1 == 1 && D2 == 2 && D3 == 3 && D4 == 4 && D5 == 5) {
        roundScore = 30;
    }
    else {
        roundScore = 0;
    }
    Little_Straight = true;
}

void evaluateBigStraight (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Big Straight category score
{

    if (D1 == 2 && D2 == 3 && D3 == 4 && D4 == 5 && D5 == 6) {
        roundScore = 30;
    }
    else {
        roundScore = 0;
    }
    Big_Straight = true;

}

void evaluateChoice (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Choice category score
{
    roundScore = D1+D2+D3+D4+D5;
    Choice = true;
}

void evaluateYacht (int D1, int D2, int D3, int D4, int D5) //function used to evaluate the Yacht category score
{
    if (D1 == D2 && D2 == D3 && D3 == D4 && D4 == D5) {
        roundScore = 50;
    }
    else {
        roundScore = 0;
    }
    Yacht = true;
}

void diceReRoll () //function used to re-roll dice
{
    cout << "Choose which dice are to be re-rolled by typing either a 1 for re-roll or a 0 to stay. " << endl;

    cout << "Re-roll Die 1: ";
    cin >> rrD1;
    cin.clear();
    cin.get();

    cout << "Re-roll Die 2: ";
    cin >> rrD2;
    cin.clear();
    cin.get();

    cout << "Re-roll Die 3: ";
    cin >> rrD3;
    cin.clear();
    cin.get();

    cout << "Re-roll Die 4: ";
    cin >> rrD4;
    cin.clear();
    cin.get();

    cout << "Re-roll Die 5: ";
    cin >> rrD5;
    cin.clear();
    cin.get();

    srand(time(NULL)); //seeds again to reset rand values

    if (rrD1 == 1) {
        Die1 = rand() % 6 + 1;
    }
    if (rrD2 == 1) {
        Die2 = rand() % 6 + 1;
    }
    if (rrD3 == 1) {
        Die3 = rand() % 6 + 1;
    }
    if (rrD4 == 1) {
        Die4 = rand() % 6 + 1;
    }
    if (rrD5 == 1) {
        Die5 = rand() % 6 + 1;
    }

    diceReRollCounter++;

}


void roundEvaluate () // uses switch cases and nested if statements, along with the above defined functions to evaluate the different choices a player makes in a round
{
    while (true) {

    cout << "\nYour dice for this round are: " << endl;
    diceView();

    cout << "\t\t\t---ROUND MENU---" << endl;
    cout << "\t\t-Categories-" << endl;
    cout << "\t|| " << "1. Ones" << "\t\t || Used: " << Ones <<endl;
    cout << "\t|| " << "2. Twos" << "\t\t || Used: " << Twos <<endl;
    cout << "\t|| " << "3. Threes" << "\t\t || Used: " <<  Threes <<endl;
    cout << "\t|| " << "4. Fours" << "\t\t || Used: " << Fours  <<endl;
    cout << "\t|| " << "5. Fives" << "\t\t || Used: " <<  Fives <<endl;
    cout << "\t|| " << "6. Sixes" << "\t\t || Used: " << Sixes <<endl;
    cout << "\t|| " << "7. Full House" << "\t || Used: " << Full_House << endl;
    cout << "\t|| " << "8. Four-Of-A-Kind" << "\t || Used: " << Four_Of_A_Kind << endl;
    cout << "\t|| " << "9. Little Straight" << "\t || Used: " <<  Little_Straight<<endl;
    cout << "\t|| " << "10. Big Straight"  << "\t || Used: " << Big_Straight <<endl;
    cout << "\t|| " << "11. Choice" << "\t\t || Used: " << Choice <<endl;
    cout << "\t|| " << "12. Yacht"  << "\t\t || Used: " << Yacht <<endl;
    cout << "\t|| " << "13. Re-roll Dice"  <<endl;

    if (Ones && Twos && Threes && Fours && Fives && Sixes && Full_House && Four_Of_A_Kind && Little_Straight && Big_Straight && Yacht && Choice) { //breaks loop when all categories are used
        break;
    }

    cin >> roundChoice; //player-input
    cin.clear();
    cin.get();
    roundScore = 0;

    switch (roundChoice) {
        case 1: //Ones
            if (Ones) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            evaluatesOnes(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 2: //Twos
            if (Twos) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            evaluateTwos(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 3: //Threes
            if (Threes) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            evaluateThrees(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 4: //Fours
            if (Fours) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            evaluateFours(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 5: //Fives
            if (Fives) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            evaluateFives(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 6: //Sixes
            if (Sixes) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            evaluateSixes(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 7: //Full House
            if (Full_House) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            sortDice(Die1,Die2,Die3,Die4,Die5);
            evaluateFullHouse(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 8: //Four of a kind
            if (Four_Of_A_Kind) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            sortDice(Die1,Die2,Die3,Die4,Die5);
            evaluateFourOfAKind(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 9: //Little Straight
            if (Little_Straight) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            sortDice(Die1,Die2,Die3,Die4,Die5);
            evaluateLittleStraight(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 10: //Big Straight
            if (Big_Straight) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            sortDice(Die1,Die2,Die3,Die4,Die5);
            evaluateBigStraight(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 11: //Choice
            if (Choice) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            evaluateChoice(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 12: //Yacht
            if (Yacht) {
                cout << "You have already used this category. " << endl;
                continue;
            }
            evaluateYacht(Die1, Die2, Die3, Die4, Die5);
            roundScoring(roundCounter, roundScore);
            break;

        case 13: //Re-roll
            if (diceReRollCounter >= 3) {
                cout << "You've already re-rolled 3 times. " << endl;
                continue;
            }
            diceReRoll();
            break;

        default: //error-handling
            cout << "That isn't a choice, input another one!" << endl;
            continue;
    }
    }
}




void mainMenu() // takes no input, displays a Main menu that asks for options - Play Game, Exit Menu
{
    while (true) {

    cout << "\nMAIN MENU" << endl;
    cout << "Pick an option for gameplay: " << endl;
    cout << "1. Play Yacht. " << endl;
    cout << "2. Exit. \n\n" << endl;
    cin >> gameChoice;
    cin.clear();
    //cin.ignore(10000,'\n');
    cin.get();

    if (gameChoice == 1) { //Play-game state, continues when over to let player play again, resets category game-states
            cout << "\nYou are now playing a game of Yacht. A game lasts 12 rounds each with 3 dice rolls. You can pick which dice to re-roll every round then pick your round category for scoring" << endl;
            roundCounter = 1;
            diceRoll(Die1, Die2, Die3, Die4, Die5);
            roundEvaluate();
            roundMenu();
            Ones = false; Twos = false; Threes = false; Fours = false; Fives = false; Sixes = false; Full_House = false; Four_Of_A_Kind = false; Little_Straight = false; Big_Straight = false; Choice = false; Yacht = false;
            continue;
    }
    else if (gameChoice == 2) { //breaks loop
        cout << "You have exited the game." << endl;
        break;
    }
    else { //error-handling
        cout << "You must enter either 1 or 2." << endl;
    }

  }
}



int main()
{
    mainMenu();
    return 0;
}
