#ifndef _RM_MOTOR_HPP_
#define _RM_MOTOR_HPP_

#include <cmath>

#include "can.h"

namespace motor_protocol
{
class RM_Motor
{
private:
  CAN_HandleTypeDef * hcan_;
  uint32_t stdid_;
  // ���CAN��������
  CAN_TxHeaderTypeDef motor_tx_message_;
  uint8_t motor_can_send_data_[8];

public:
  // �������
  struct motor_measure_t
  {
    uint16_t ecd;           // ���������λ��
    uint16_t last_ecd;      // ��һ�ε��������λ��
    float angle;            // ���ת�ӽǶȣ�rad��
    int16_t revolutions;    // ���ת��ת��Ȧ��
    double rev_angle;       // ��Ȧ�����ת�ӽǶȣ�rad��
    int16_t speed_rpm;      // ���ת�٣�ת/���ӣ�
    float speed;            // ���ת�٣�rad/s��
    int16_t given_current;  // ���ʵ�ʵ���
    uint8_t temperate;      // ����¶�
  } motor_measure_[4];
  RM_Motor(CAN_HandleTypeDef * hcan, uint32_t stdid);
  ~RM_Motor() {}
  // ���͵������ָ��
  HAL_StatusTypeDef motor_cmd(int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4);
  // ����������
  void decode_motor_measure(uint8_t motor_id, uint8_t data[8]);
};

}  // namespace motor_protocol

#endif  // _RM_MOTOR_HPP_