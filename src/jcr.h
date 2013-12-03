/*
 * jcr.h
 *
 *  Created on: Feb 15, 2012
 *      Author: fumin
 */

#ifndef Jcr_H_
#define Jcr_H_

#include "destor.h"
#include "recipe/recipestore.h"

/* job control record */
struct {
	int32_t id;
	sds path; //backup/restore path

	int32_t file_num;
	int64_t data_size;
	int64_t unique_data_size;
	int32_t chunk_num;
	int32_t unique_chunk_num;
	int32_t zero_chunk_num;
	int64_t zero_chunk_size;
	int32_t rewritten_chunk_num;
	int64_t rewritten_chunk_size;

	int32_t sparse_container_num;
	int32_t inherited_sparse_num;
	int32_t total_container_num;

	struct backupVersion* bv;

	double total_time;
	/*
	 * the time consuming of six dedup phase
	 */
	double read_time;
	double chunk_time;
	double hash_time;
	double filter_time;
	double write_time;
	/*	double test_time;*/

	double read_chunk_time;
	double write_file_time;
} jcr;

void init_backup_jcr(char *path);
void init_restore_jcr(int revision, char *path);

#endif /* Jcr_H_ */
