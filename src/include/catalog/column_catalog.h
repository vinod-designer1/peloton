//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// column_catalog.h
//
// Identification: src/include/catalog/column_catalog.h
//
// Copyright (c) 2015-17, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// pg_attribute
//
// Schema: (column: column_name)
// 0: table_id (pkey), 1: column_name (pkey), 2: column_offset, 3: column_type,
// 4: is_inlined, 5: is_primary, 6: is_not_null
//
// Indexes: (index offset: indexed columns)
// 0: table_id & column_name
// 1: table_id & column_offset
//
//===----------------------------------------------------------------------===//

#pragma once

#include "catalog/abstract_catalog.h"

namespace peloton {
namespace catalog {

class ColumnCatalog : public AbstractCatalog {
 public:
  // Global Singleton
  static ColumnCatalog *GetInstance(storage::Database *pg_catalog = nullptr,
                                    type::AbstractPool *pool = nullptr);

  inline oid_t GetNextOid() { return oid_++ | TABLE_OID_MASK; }

  // Write related API
  bool Insert(oid_t table_id, const std::string &column_name,
              oid_t column_offset, type::Type::TypeId column_type,
              bool is_inlined, std::vector<ConstraintType> constraints,
              type::AbstractPool *pool, concurrency::Transaction *txn);
  bool DeleteByOidWithName(oid_t table_id, const std::string &column_name,
                           concurrency::Transaction *txn);

  // Read-only API
  oid_t GetOffsetByOidWithName(oid_t table_id, const std::string &column_name,
                               concurrency::Transaction *txn);
  std::string GetNameByOidWithOffset(oid_t table_id, oid_t column_offset,
                                     concurrency::Transaction *txn);
  type::TypeId GetTypeByOidWithName(oid_t table_id, std::string column_name,
                                    concurrency::Transaction *txn);
  type::TypeId GetTypeByOidWithOffset(oid_t table_id, oid_t column_offset,
                                      concurrency::Transaction *txn);

 private:
  ColumnCatalog(storage::Database *pg_catalog, type::AbstractPool *pool);

  ~ColumnCatalog();

  std::unique_ptr<catalog::Schema> InitializeSchema();
};

}  // End catalog namespace
}  // End peloton namespace