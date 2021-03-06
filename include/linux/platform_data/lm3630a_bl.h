/*
* Simple driver for Texas Instruments LM3630A LED Flash driver chip
* Copyright (C) 2012 Texas Instruments
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
*/

#ifndef __LINUX_LM3630A_H
#define __LINUX_LM3630A_H

#define LM3630A_NAME "lm3630a_bl"

enum lm3630a_pwm_ctrl {
	LM3630A_PWM_DISABLE = 0x00,
	LM3630A_PWM_BANK_A,
	LM3630A_PWM_BANK_B,
	LM3630A_PWM_BANK_ALL,
	LM3630A_PWM_BANK_A_ACT_LOW = 0x05,
	LM3630A_PWM_BANK_B_ACT_LOW,
	LM3630A_PWM_BANK_ALL_ACT_LOW,
};

enum lm3630a_leda_ctrl {
	LM3630A_LEDA_DISABLE = 0x00,
	LM3630A_LEDA_ENABLE = 0x04,
	LM3630A_LEDA_ENABLE_LINEAR = 0x14,
};

enum lm3630a_ledb_ctrl {
	LM3630A_LEDB_DISABLE = 0x00,
	LM3630A_LEDB_ON_A = 0x01,
	LM3630A_LEDB_ENABLE = 0x02,
	LM3630A_LEDB_ENABLE_LINEAR = 0x0A,
};

enum lm3630a_sleep_ctrl {
	LM3630A_SLEEP_ENABLE = 0x80,
	LM3630A_SLEEP_STATUS = 0x40,
};

/*
 *@leda_init_brt : led a init brightness. 4~255
 *@leda_max_brt  : led a max brightness.  4~255
 *@leda_ctrl     : led a disable, enable linear, enable exponential
 *@ledb_init_brt : led b init brightness. 4~255
 *@ledb_max_brt  : led b max brightness.  4~255
 *@ledb_ctrl     : led b disable, enable linear, enable exponential
 *@pwm_period    : pwm period
 *@pwm_ctrl      : pwm disable, bank a or b, active high or low
 */
struct lm3630a_platform_data {

	/* led a config.  */
	int leda_init_brt;
	int leda_max_brt;
	int leda_max_cur;
	int leda_max_hbm_cur;
	enum lm3630a_leda_ctrl leda_ctrl;
	/* led b config. */
	int ledb_init_brt;
	int ledb_max_brt;
	int ledb_max_cur;
	int ledb_max_hbm_cur;
	enum lm3630a_ledb_ctrl ledb_ctrl;
	/* pwm config. */
	int pwm_gpio;
	unsigned int pwm_period;
	enum lm3630a_pwm_ctrl pwm_ctrl;
	int config;
	int flt_str;
	/* hardware control */
	int hwen_gpio;
	char vddio_name[32];
	/* misc */
	int boost_ctrl;
	bool skip_init_config;
};

#endif /* __LINUX_LM3630A_H */
