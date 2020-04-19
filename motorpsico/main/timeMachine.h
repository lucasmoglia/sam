  int getElapsedTime(unsigned long _startTime){
    return millis() - _startTime;
  }

  int checkMaxTime(unsigned long _startTime, int _max){
    return getElapsedTime(_startTime) >= _max;
  }

  
