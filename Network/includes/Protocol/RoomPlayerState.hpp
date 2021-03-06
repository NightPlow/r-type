//
// Created by Quentin Liardeaux on 12/18/19.
//

#ifndef R_TYPE_ROOMPLAYERSTATE_HPP
#define R_TYPE_ROOMPLAYERSTATE_HPP

#include <string>
#include <memory>

#include "Message.hpp"
#include "protocol.hpp"

class RoomPlayerState : public Message {
public:
    RoomPlayerState(size_t idPlayer, std::string nickname, bool isReady)
            : Message(TCP_COMMUNICATION::ROOM_PLAYER_STATE)
            , m_idPlayer(idPlayer)
            , m_nickname(std::move(nickname))
            , m_isReady(isReady)
    {}
    ~RoomPlayerState() override = default;

    static std::unique_ptr<Message> from(void *data);

    [[nodiscard]] std::vector<uint8_t> serialize() const override;
    size_t getSize() const final { return PACKET_HDR_SIZE + ROOM_PLAYER_STATE_SIZE; }

    size_t getIdPlayer() const { return m_idPlayer; }
    const std::string &getNickname() const { return m_nickname; }
    bool getIsReady() const { return m_isReady; }
private:
    size_t m_idPlayer;
    std::string m_nickname;
    bool m_isReady;
};

#endif //R_TYPE_ROOMPLAYERSTATE_HPP
