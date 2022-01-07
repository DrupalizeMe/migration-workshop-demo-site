This example data is taken from the 2018.tcdrupal.org website. It's been sanitized to remove sensitive personal information. And is intended only for use as example data.

Files:

- d7files.tar.gz contains the sites/default/files directory
- d7site.sql.gz contains a SQL dump database snapshot

The following SQL was used to sanitize the data from the original site:

```sql
DELIMITER $$

CREATE DEFINER=`root`@`%` FUNCTION `RandString`(length SMALLINT(3)) RETURNS varchar(100) CHARSET utf8
begin
    SET @returnStr = '';
    SET @allowedChars = 'abcdefghijklmnopqrstuvwxyz0123456789';
    SET @i = 0;

    WHILE (@i < length) DO
        SET @returnStr = CONCAT(@returnStr, substring(@allowedChars, FLOOR(RAND() * LENGTH(@allowedChars) + 1), 1));
        SET @i = @i + 1;
    END WHILE;

    RETURN @returnStr;
END

UPDATE commerce_line_item SET line_item_label = CONCAT('commerce_coupon_fixed: c', line_item_id) WHERE type="commerce_coupon";
UPDATE commerce_order SET mail = CONCAT('email-', order_id, '@example.com');
UPDATE commerce_order_revision SET mail = CONCAT('email-', order_id, '@example.com');
UPDATE commerce_paypal_ipn SET payer_email = CONCAT('email-', order_id, '@example.com');
UPDATE commerce_payment_transaction SET payload="a:0:{}"
UPDATE field_data_commerce_coupon_code SET commerce_coupon_code_value = CONCAT('COUPON', entity_id);
UPDATE field_revision_commerce_coupon_code SET commerce_coupon_code_value = CONCAT('COUPON', entity_id);
UPDATE field_data_commerce_customer_address SET commerce_customer_address_thoroughfare = CONCAT(entity_id, ' Anywhere St.'), commerce_customer_address_premise = "", commerce_customer_address_name_line = CONCAT('Name', entity_id, ' Last', entity_id), commerce_customer_address_first_name = CONCAT('Name', entity_id), commerce_customer_address_last_name = CONCAT('Last', entity_id);
UPDATE field_revision_commerce_customer_address SET commerce_customer_address_thoroughfare = CONCAT(entity_id, ' Anywhere St.'), commerce_customer_address_premise = "", commerce_customer_address_name_line = CONCAT('Name', entity_id, ' Last', entity_id), commerce_customer_address_first_name = CONCAT('Name', entity_id), commerce_customer_address_last_name = CONCAT('Last', entity_id);
UPDATE field_data_field_company SET field_company_value = CONCAT('Company', entity_id, ' Name');
UPDATE field_revision_field_company SET field_company_value = CONCAT('Company', entity_id, ' Name');
UPDATE field_data_field_first_name SET field_first_name_value = RANDSTRING(FLOOR(RAND() * 10) + 2);
UPDATE field_revision_field_first_name SET field_first_name_value = RANDSTRING(FLOOR(RAND() * 10) + 2);
UPDATE field_data_field_last_name SET field_last_name_value = RANDSTRING(FLOOR(RAND() * 10) + 6);
UPDATE field_revision_field_last_name SET field_last_name_value = RANDSTRING(FLOOR(RAND() * 10) + 6);
UPDATE field_data_field_registration_do_username SET field_registration_do_username_value = RANDSTRING(FLOOR(RAND() * 10) + 6);
UPDATE field_revision_field_registration_do_username SET field_registration_do_username_value = RANDSTRING(FLOOR(RAND() * 10) + 6);
UPDATE field_data_field_sponsor_contact_email SET field_sponsor_contact_email_value = CONCAT('sponsor', entity_id, '@example.com');
UPDATE field_revision_field_sponsor_contact_email SET field_sponsor_contact_email_value = CONCAT('sponsor', entity_id, '@example.com');
UPDATE field_data_field_sponsor_contact_name SET field_sponsor_contact_name_value = RANDSTRING(FLOOR(RAND() * 10) + 6);
UPDATE field_revision_field_sponsor_contact_name SET field_sponsor_contact_name_value = RANDSTRING(FLOOR(RAND() * 10) + 6);
UPDATE field_data_field_sponsor_contact_phone SET field_sponsor_contact_phone_value = "6128675309"
UPDATE field_revision_field_sponsor_contact_phone SET field_sponsor_contact_phone_value = "6128675309"
UPDATE users SET name = RANDSTRING(FLOOR(RAND() * 10) + 4), mail = CONCAT(name, '@example.com'), init = CONCAT(name, '@example.com');
UPDATE webform_submitted_data SET data = CONCAT('email', nid, '@example.com') WHERE cid = 19;
```
