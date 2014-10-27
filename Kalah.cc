#include "Kalah.h"

// centered(string) command for pretty printing
template<typename charT, typename traits = std::char_traits<charT> >
class center_helper {
    std::basic_string<charT, traits> str_;
public:
    center_helper(std::basic_string<charT, traits> str) : str_(str) {}
    template<typename a, typename b>
    friend std::basic_ostream<a, b>& operator<<(std::basic_ostream<a, b>& s, const center_helper<a, b>& c);
};

template<typename charT, typename traits = std::char_traits<charT> >
center_helper<charT, traits> centered(std::basic_string<charT, traits> str) {
    return center_helper<charT, traits>(str);
}

// redeclare for std::string directly so we can support anything that implicitly converts to std::string
center_helper<std::string::value_type, std::string::traits_type> centered(const std::string& str) {
    return center_helper<char>(str);
}

template<typename charT, typename traits >
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& s, const center_helper<charT, traits>& c) {
    std::streamsize w = s.width();
    if (w > c.str_.length()) {
        std::streamsize left = (w + c.str_.length()) / 2;
        s.width(left);
        s << c.str_;
        s.width(w - left);
        s << "";
    } else {
        s << c.str_;
    }
    return s;
}

void Kalah::PrintOpening(){
  cout<<setfill('=')<<setw(109)<<'='<<endl;
  cout<<"="<<setfill(' ')<<setw(107)<<centered("WELCOME TO KALAH")<<"="<<endl;
  cout<<"="<<setfill(' ')<<setw(107)<<centered("By Brian Pollack")<<"="<<endl;
  cout<<"="<<setfill(' ')<<setw(107)<<" "<<"="<<endl;
  cout<<"="<<setfill(' ')<<setw(107)<<centered("You cannot win, puny human")<<"="<<endl;
  cout<<"="<<setfill(' ')<<setw(107)<<centered("Confused? Type 'rules'.")<<"="<<endl;
  string answer;
  cout<<"="<<setfill(' ')<<setw(107)<<centered("Do you still want to play? (yes/no)")<<"="<<endl;
  cin >> answer;
  transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
  while(answer[0] != 'y' && answer[0] != 'n' && answer != "quit" && answer != "exit" && answer[0] != 'r'){
    cout<<"="<<setfill(' ')<<setw(107)<<centered("Good job human, you failed the yes/no portion of this exam.  Try again.")<<"="<<endl;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
  }
  if (answer[0] == 'y'){
    cout<<"="<<setfill(' ')<<setw(107)<<centered("HA! You are truly a fool. Let us \"play.\"")<<"="<<endl;
    this_thread::sleep_for (chrono::milliseconds(1500));
  }else if (answer[0] == 'n' || (answer == "quit") || (answer == "exit")){
    cout<<"="<<setfill(' ')<<setw(107)<<centered("Wise choice. Leave with your dignity intact.")<<"="<<endl;
    cout<<setfill('=')<<setw(109)<<'='<<endl;
    this_thread::sleep_for (chrono::milliseconds(1500));
    exit(0);
  }else if( answer[0] == 'r'){
    PrintRules();
  }
}

void Kalah::PrintRules(){
  cout<<setfill('=')<<setw(109)<<'='<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"RULES OF KALAH"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"The goal of the game is to store the most seeds!"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"Each player starts with 30 total seeds, randomly distributed in circles A-F"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"When it is your turn, you choose a circle from A-F."<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"All N seeds are removed from that circle, and you move N circles in a counter-clockwise direction,"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"placing a seed in each circle you visit (including your opponent's, if you keep moving past your store!)"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"If a seed lands in your store at the far right, you gain a point! You cannot remove seeds from your store."<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"You skip your opponent's store if you have enough seeds to wrap around to your side of the board."<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"You cannot choose a circle with 0 seeds."<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"Special Rules:"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<" 1) If your last seed from a given move is placed in your store, you get to go again!"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<" 2) If your last seed lands in an empty circle on your side, and your opponent has 1 or more seeds in the"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"    circle directly across from it, you store your seed and all the seeds in your opponent's circle!:"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<" 3) If it is your turn and you have no seeds in your circles, the game is over and your opponent"<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"    stores all remaining seeds on their side of the board."<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<" "<<"="<<endl;
  cout<<"= "<<setfill(' ')<<setw(106)<<left<<"The first to 31 or more stored seeds win!"<<"="<<endl;
  string answer;
  cout<<"="<<setfill(' ')<<setw(107)<<right<<centered("Do you still want to play? (yes/no)")<<"="<<endl;
  cin >> answer;
  transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
  while(answer[0] != 'y' && answer[0] != 'n' && answer != "quit" && answer != "exit" && answer[0] != 'r'){
    cout<<"="<<setfill(' ')<<setw(107)<<centered("Good job human, you failed the yes/no portion of this exam.  Try again.")<<"="<<endl;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
  }
  if (answer[0] == 'y'){
    cout<<"="<<setfill(' ')<<setw(107)<<centered("HA! You are truly a fool. Let us \"play.\"")<<"="<<endl;
    this_thread::sleep_for (chrono::milliseconds(1500));
  }else if (answer[0] == 'n' || (answer == "quit") || (answer == "exit")){
    cout<<"="<<setfill(' ')<<setw(107)<<centered("Wise choice. Leave with your dignity intact.")<<"="<<endl;
    cout<<setfill('=')<<setw(109)<<'='<<endl;
    this_thread::sleep_for (chrono::milliseconds(1500));
    exit(0);
  }else if( answer[0] == 'r'){
    PrintRules();
  }
}

void Kalah::Init(){
  for (int i =0; i<14; i++) board[i] = 0;
  humanScore = aiScore = 0;
  humanTurn = true;
  random_device rd;
  default_random_engine generator(rd());
  uniform_int_distribution<int> distribution(0,5);
  auto dice = std::bind ( distribution, generator );
  for (int i = 0; i<30; i++){
    board[dice()]+=1;
    board[dice()+7]+=1;
  }
}

void Kalah::PrintBoard(){
  cout<<setfill('=')<<setw(109)<<'='<<endl;
  cout<<"==============";
  for (int i = 0; i <6; i++){
    cout<<"      "<<"=========";
  }
  cout<<"====="<<                     endl;
  cout<<"===       ===";
  for (int i = 0; i <6; i++){
    cout<<setfill(' ')<<setw(8)<<centered(to_string(board[12-i]));
    if (i<5) cout<<"=======";
  }
  cout<<"===       ==="<<             endl;
  cout<<"=="<<setw(9)<<setfill(' ')
  <<centered("AI")<<"===";        
  for (int i = 0; i <6; i++){
    cout<<"      ";
    if(i<5) cout<<"=========";
  }
  cout<<"==="<<setw(9)<<setfill(' ')
  <<centered("HUMAN")<<"=="<<         endl;
  cout<<"=";
  cout<<setfill(' ')<<setw(11)<<centered(to_string(board[13]));
  cout<<setfill('=')<<setw(85)<<'=';
  cout<<setfill(' ')<<setw(11)<<centered(to_string(board[6]));
  cout<<"="<<                         endl;
  cout<<"==         ===";
  for (int i = 0; i <6; i++){
    cout<<"      ";
    if(i<5) cout<<"=========";
  }
  cout<<"===         =="<<            endl;
  cout<<"===       ===";
  for (int i = 0; i <6; i++){
    cout<<setfill(' ')<<setw(8)<<centered(to_string(board[i]));
    if (i<5) cout<<"=======";
  }
  cout<<"===       ==="<<             endl;
  cout<<"==============";
  for (int i = 0; i <6; i++){
    cout<<setfill(' ')<<setw(6)<<centered(boardKeys[i]);
    cout<<"=========";
  }
  cout<<"====="<<endl;
  cout<<setfill('=')<<setw(109)<<'='<<endl;
}

void Kalah::ExecuteMove(int position){

  int mySeeds = board[position];
  board[position] = 0;
  int j = position+1;
  for (int i = position+1; i<=mySeeds+position; i++){
    if (humanTurn && j%14 == 13) j+=1;
    else if (!humanTurn && j%14 == 6) j+=1;
    board[j%14] +=1;
    j+=1;
  }
  CheckCapture((j-1)%14);
  humanScore = board[6];
  aiScore = board[13];
  if(humanTurn){
    if((j-1)%14 != 6) humanTurn = false;
  }else{
    if((j-1)%14 != 13) humanTurn = true;
  }
  PrintBoard();
}

float Kalah::PseudoExecuteMove(int position){
  int fakeBoard[14];
  copy(begin(board), end(board), begin(fakeBoard));
  int mySeeds = fakeBoard[position];
  if (mySeeds == 0) return -1.0;
  fakeBoard[position] = 0;
  int j = position+1;
  for (int i = position+1; i<=mySeeds+position; i++){
    if (j%14 == 6) j+=1;
    fakeBoard[j%14] +=1;
    j+=1;
  }
  PseudoCheckCapture((j-1)%14,fakeBoard);
  int fakeAiScore = fakeBoard[13];
  int totalScore = fakeAiScore-aiScore;
  bool gainMove = false;
  if((j-1)%14 == 13) gainMove = true;
  float quality = totalScore + 2*gainMove + gainMove*0.1*(position-6);
  return quality;
}

bool Kalah::WinCondition(){
  if(aiScore > 30 || humanScore > 30) return true;
  if(humanTurn && *max_element(board,board+6) == 0){
    for (int i =7; i<13; i++){
      board[13] += board[i];
      board[i] = 0;
    }
    aiScore = board[13];
    return true;
  }else if(!humanTurn && *max_element(board+7,board+13) == 0){
    for (int i =0; i<6; i++){
      board[6] += board[i];
      board[i] = 0;
    }
    humanScore = board[6];
    return true;
  }
  else return false;
}

int Kalah::HumanMove(){
  string answer;
  cout<<"Which pile do you want to move? (A,B,C,D,E,F)"<<endl;
  cin >> answer;
  transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
  while(answer != "A" && answer != "B" && answer != "C" && answer != "D" && answer != "E" && answer != "F"){
    cout<<"This isn't difficult, try to answer competently."<<endl;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
  }
  return boardMap[answer];
}

void Kalah::CheckCapture(int pos){
  if (pos == 6 || pos == 13) return;
  if ((humanTurn && pos>5) || (!humanTurn && pos<6)) return;
  if (board[pos] != 1) return;
  else{
    if (board[12-pos] == 0) return;
    else{
      if (humanTurn){
        board[pos] = 0;
        board[6] += 1;
        board[6] += board[12-pos];
        board[12-pos]=0;
      }else{
        board[pos] = 0;
        board[13] += 1;
        board[13] += board[12-pos];
        cout<<"Ha! I captured "<<board[12-pos]<<" of your seeds!"<<endl;
        board[12-pos]=0;
      }
    }
  }
}

void Kalah::PseudoCheckCapture(int pos, int fakeBoard[14]){
  if (pos == 6 || pos == 13) return;
  if (pos<6) return;
  if (fakeBoard[pos] != 1) return;
  else{
    if (fakeBoard[12-pos] == 0) return;
    else{
      fakeBoard[pos] = 0;
      fakeBoard[13] += 1;
      fakeBoard[13] += fakeBoard[12-pos];
      fakeBoard[12-pos]=0;
    }
  }
}

int Kalah::Think(){
  map<float, int> possibleMoves;
  for (int i =7; i<13; i++){
    possibleMoves[PseudoExecuteMove(i)]=i;
  }
  return possibleMoves.rbegin()->second;
}


void Kalah::PostGame(){
  cout<<"THE FINAL SCORE"<<endl;
  PrintBoard();
  if (humanScore == aiScore){
    cout<<"A TIE?! Great, we're both losers. Let's play again. (yes/no)"<<endl;
  }else if(humanScore < aiScore){
    cout<<"I win, but I could have told you that before we even started. Do you want to waste my time again? (yes/no)"<<endl;
  }else{
    cout<<"I... lost?! You must have cheated! The sun was in my eyes! I demand we play again! (yes/no)"<<endl;
  }
  string answer;
  cin >> answer;
  transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
  while(answer[0] != 'y' && answer[0] != 'n' && answer != "quit" && answer != "exit"){
    cout<<"="<<setfill(' ')<<setw(107)<<centered("I have no time for your nonsense. Try again.")<<"="<<endl;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
  }
  if (answer[0] == 'y'){
    cout<<"="<<setfill(' ')<<setw(107)<<centered("Once more into the breach.")<<"="<<endl;
    this_thread::sleep_for (chrono::milliseconds(1500));
  }else if (answer[0] == 'n' || (answer == "quit") || (answer == "exit")){
    cout<<"="<<setfill(' ')<<setw(107)<<centered("Leave me be, I have computations to compute.")<<"="<<endl;
    cout<<setfill('=')<<setw(109)<<'='<<endl;
    this_thread::sleep_for (chrono::milliseconds(500));
    exit(0);
  }
  StartGame();
}

void Kalah::PlayGame(){
  //random_device rd;
  //default_random_engine generator(rd());
  while(!WinCondition()){
    int pileNumber; 
    if(humanTurn){
      cout<<"YOUR MOVE, HUMAN"<<endl;
      pileNumber = HumanMove();
      while(board[pileNumber] == 0){
        cout<<"You cannot move 0 seeds, human. Choose again."<<endl;
        pileNumber = HumanMove();
      }

    }else{
      cout<<"MY MOVE"<<endl;
      //uniform_int_distribution<int> distribution(7,12);
      //pileNumber = distribution(generator);
      pileNumber = Think();
      cout<<"I chose the pile across from "<<boardMapAI[pileNumber]<<endl;
      this_thread::sleep_for (chrono::milliseconds(1000));
    }
    ExecuteMove(pileNumber);
  }
  PostGame();
}



void Kalah::StartGame(){
  Init();
  PrintBoard();
  PlayGame();
}


