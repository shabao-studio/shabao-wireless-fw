/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

                                      ---

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes ChibiOS/RT, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
*/

#include "ch.h"
#include "hal.h"

#include "fc_threads.h"
#include "fc_nrf24l01.h"

/*
 * NRF thread
 */
static WORKING_AREA(NRFThreadWA, 256);
static msg_t NRFThread(void *arg) {
	chRegSetThreadName("NRFThread");
	(void)arg;
	while (TRUE) {
		NRFHandleIrq();
	}
	return 0;
}

/*
 * Start Threads
 */
void startThreads(void)
{
	/*
	 * Create NRF thread
	 */
	chThdCreateStatic(NRFThreadWA,
			sizeof(NRFThreadWA),
			NORMALPRIO,
			NRFThread,
			NULL);
}
