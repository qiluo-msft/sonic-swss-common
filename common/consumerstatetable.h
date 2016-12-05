#pragma once

#include <string>
#include <vector>
#include "dbconnector.h"
#include "table.h"
#include "redisselect.h"

namespace swss {

class ConsumerStateTable : public RedisTransactioner, public RedisSelect, public TableName_KeySet, public TableEntryPoppable
{
public:
    const int POP_BATCH_SIZE;

    ConsumerStateTable(DBConnector *db, std::string tableName);

    /* Get a singlesubsribe channel rpop */
    /* If there is nothing to pop, the output paramter will have empty key and op */
    void pop(KeyOpFieldsValuesTuple &kco, std::string prefix = EMPTY_PREFIX);

    /* Get multiple pop elements */
    void pops(std::vector<KeyOpFieldsValuesTuple> &vkco, std::string prefix = EMPTY_PREFIX);
};

}