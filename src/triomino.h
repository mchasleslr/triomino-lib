/**
 * @file       triomino.h
 *
 * @author     Christophe Demko <christophe.demko@univ-lr.fr>
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#ifndef TRIOMINO_H_
#define TRIOMINO_H_

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Triomino type
 * @details A triomino is a piece with three corners named a, b and c.
 * @details Each corner has a value between 0 and 5.
 * @details The corners are ordered from the smallest to the largest value.
 * @details The triomino is represented by the values of its corners.
 */
typedef struct _Triomino Triomino;

/**
 * @brief Memory allocation functions.
 */
extern void *(*triomino_malloc)(size_t size);
extern void *(*triomino_calloc)(size_t nmemb, size_t size);
extern void *(*triomino_realloc)(void *ptr, size_t size);
extern void (*triomino_free)(void *ptr);

/**
 * @brief Initialize the triomino module.
 * @return true on success, false on failure.
 */
extern bool triomino_init(void);
/**
 * @brief Finalize the triomino module.
 * @return true on success, false on failure.
 */
extern bool triomino_finish(void);

/**
 * @brief Fill a triomino with the given values.
 * @param triomino The triomino to fill.
 * @param a The value of the first corner.
 * @param b The value of the second corner.
 * @param c The value of the third corner.
 * @return The triomino filled.
 * @pre a <= 5
 * @pre b <= 5
 * @pre c <= 5
 * @pre a <= b
 * @pre b <= c
 */
extern Triomino *triomino_fill_full(Triomino *triomino, unsigned char a, unsigned char b, unsigned char c);
/**
 * @brief Reset a triomino.
 * @param triomino The triomino to reset.
 * @return The triomino reset.
 * @details The triomino is reset to 0, 0 and 0.
 */
extern Triomino *triomino_reset(Triomino *triomino);
/**
 * @brief Create a triomino with the given values.
 * @param a The value of the first corner.
 * @param b The value of the second corner.
 * @param c The value of the third corner.
 * @return The triomino created.
 * @pre a <= 5
 * @pre b <= 5
 * @pre c <= 5
 * @pre a <= b
 * @pre b <= c
 */
extern Triomino *triomino_create_full(unsigned char a, unsigned char b, unsigned char c);
/**
 * @brief Create a triomino with default values.
 * @return The triomino created.
 * @details The default values are 0, 0 and 0.
 */
extern Triomino *triomino_create_default(void);
/**
 * @brief Destroy a triomino.
 * @param triomino The triomino to destroy.
 */
extern void triomino_destroy(Triomino *triomino);

/**
 * @brief Get the value of the first corner of a triomino.
 * @param triomino The triomino.
 * @return The value of the first corner.
 */
extern unsigned char triomino_get_a(const Triomino *triomino);
/**
 * @brief Get the value of the second corner of a triomino.
 * @param triomino The triomino.
 * @return The value of the second corner.
 */
extern unsigned char triomino_get_b(const Triomino *triomino);
/**
 * @brief Get the value of the third corner of a triomino.
 * @param triomino The triomino.
 * @return The value of the third corner.
 */
extern unsigned char triomino_get_c(const Triomino *triomino);

/**
 * @brief Clone a triomino.
 * @param triomino The triomino to clone.
 * @return The cloned triomino.
 */
extern Triomino *triomino_clone(const Triomino *triomino);
/**
 * @brief Copy a triomino.
 * @param dest The destination triomino.
 * @param src The source triomino.
 * @return The destination triomino.
 */
extern Triomino *triomino_copy(Triomino *dest, const Triomino *src);

/**
 * @brief Check if two triominos are aa compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if the a corner of triomino1
 *       is equal to the a corner of triomino2.
 */
extern bool triomino_aa_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ab compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if the a corner of triomino1
 *       is equal to the b corner of triomino2.
 */
extern bool triomino_ab_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ac compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if the a corner of triomino1
 *       is equal to the c corner of triomino2.
 */
extern bool triomino_ac_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ba compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if the b corner of triomino1
 *       is equal to the a corner of triomino2.
 */
extern bool triomino_ba_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are bb compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if the b corner of triomino1
 *       is equal to the b corner of triomino2.
 */
extern bool triomino_bb_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are bc compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if the b corner of triomino1
 *       is equal to the c corner of triomino2.
 */
extern bool triomino_bc_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ca compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if the c corner of triomino1
 *       is equal to the a corner of triomino2.
 */
extern bool triomino_ca_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are cb compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if the c corner of triomino1
 *       is equal to the b corner of triomino2.
 */
extern bool triomino_cb_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are cc compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if the c corner of triomino1
 *       is equal to the c corner of triomino2.
 */
extern bool triomino_cc_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ab-cb compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if they have two sides equal.
 *       The sides are ab for triomino1 and cb for triomino2.
 */
extern bool triomino_ab_cb_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ab-ba compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if they have two sides equal.
 *       The sides are ab for triomino1 and ba for triomino2.
 */
extern bool triomino_ab_ba_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ab-ac compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if they have two sides equal.
 *       The sides are ab for triomino1 and ac for triomino2.
 */
extern bool triomino_ab_ac_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are bc-cb compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if they have two sides equal.
 *       The sides are bc for triomino1 and cb for triomino2.
 */
extern bool triomino_bc_cb_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are bc-ba compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if they have two sides equal.
 *       The sides are bc for triomino1 and ba for triomino2.
 */
extern bool triomino_bc_ba_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are bc-ac compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if they have two sides equal.
 *       The sides are bc for triomino1 and ac for triomino2.
 */
extern bool triomino_bc_ac_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ca-cb compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if they have two sides equal.
 *       The sides are ca for triomino1 and cb for triomino2.
 */
extern bool triomino_ca_cb_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ca-ba compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if they have two sides equal.
 *       The sides are ca for triomino1 and ba for triomino2.
 */
extern bool triomino_ca_ba_compatible(const Triomino *triomino1, const Triomino *triomino2);
/**
 * @brief Check if two triominos are ca-ac compatible.
 * @param triomino1 The first triomino.
 * @param triomino2 The second triomino.
 * @return true if the triominos are compatible, false otherwise.
 * @note The triominos are compatible if they have two sides equal.
 *       The sides are ca for triomino1 and ac for triomino2.
 */
extern bool triomino_ca_ac_compatible(const Triomino *triomino1, const Triomino *triomino2);

/**
 * @brief Write a triomino to a stream.
 * @param triomino The triomino.
 * @param stream The stream.
 * @return The triomino written.
 */
extern Triomino *triomino_fwrite(const Triomino *triomino, FILE *stream);
/**
 * @brief Read a triomino from a stream.
 * @param triomino The triomino.
 * @param stream The stream.
 * @return The triomino read.
 */
extern Triomino *triomino_fread(Triomino *triomino, FILE *stream);

/**
 * @brief Convert a triomino to a string.
 * @param triomino The triomino.
 * @return The string representation of the triomino.
 */
extern const char *triomino_to_string(const Triomino *triomino);

#endif // TRIOMINO_H_
