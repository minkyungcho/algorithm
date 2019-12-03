#include <vector>
#include <map>

using namespace std;

long long checkRoom(map<long long, long long>& rooms, long long targetRoom, vector<long long>& answer) {
    if (rooms.find(targetRoom) != rooms.end()) {
        long long alterRoom = rooms[targetRoom];
        
        rooms[targetRoom] = checkRoom(rooms, alterRoom, answer);
        return rooms[targetRoom];
    }

    else {
        answer.push_back(targetRoom);

        if (rooms.find(targetRoom + 1) != rooms.end()) {
            rooms[targetRoom] = rooms[targetRoom + 1];
        }

        else {
            rooms[targetRoom] = targetRoom + 1;
        }
        
        return rooms[targetRoom];
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    map<long long, long long> rooms;
    
    for (long long i = 0 ; i < room_number.size(); i++) {
        long long targetRoom = room_number[i];
        
        checkRoom(rooms, targetRoom, answer);
    }
    
    return answer;
}