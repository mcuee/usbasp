/* Name: uart.h
 *
 * UART support 
 *
 * 2016 original implementation Adam Krasuski (https://github.com/akrasuski1)
 * 2021 tweaks by Dimitrios Chr. Ioannidis ( d.ioannidis@nephelae.eu )
 *
 * Tabsize: 4
 * License: GNU GPL v2 (see Readme.txt)
 */

#ifndef UART_H
#define UART_H

#include "cbuf.h"
#include "usbasp.h"
#include <stdint.h>

#define rx_Q_SIZE   128
#define tx_Q_SIZE   128

volatile struct
{
    uint8_t m_getIdx;
    uint8_t m_putIdx;
    uint8_t m_entry[rx_Q_SIZE];
} rx_Q;

volatile struct
{
    uint8_t m_getIdx;
    uint8_t m_putIdx;
    uint8_t m_entry[tx_Q_SIZE];
} tx_Q;

void uart_config(uint16_t baud, uint8_t par, uint8_t stop, uint8_t bytes);
void uart_disable();

#endif // UART_H
