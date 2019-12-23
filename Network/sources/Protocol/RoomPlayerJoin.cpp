//
// Created by Quentin Liardeaux on 12/18/19.
//

#include "Protocol/RoomPlayerJoin.hpp"

RoomPlayerJoin::RoomPlayerJoin(void *data) : Message(ROOM_PLAYER_JOIN) {
    auto pkt = reinterpret_cast<room_player_join_t*>(data);

    m_idPlayer = pkt->id_player;
    m_nickname = std::string(reinterpret_cast<char *>(pkt->nickname));
    m_isReady = pkt->is_ready;
}

std::vector<uint8_t> RoomPlayerJoin::serialize() const {
    std::vector<uint8_t> data = Message::createHeader(m_id, ROOM_PLAYER_JOIN);
    room_player_join_t pkt = {m_idPlayer, {0}, m_isReady};

    for (size_t i = 0; i < m_nickname.size() && i < MAX_BUFFER_SIZE; i++)
        pkt.nickname[i] = static_cast<uint8_t>(*(m_nickname.c_str() + i));
    for (size_t i = 0; i < JOIN_GAME_SIZE; i++)
        data.push_back(*(reinterpret_cast<uint8_t *>(&pkt) + i));
    return data;
}