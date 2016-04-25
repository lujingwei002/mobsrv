module('Mailsrv', package.seeall)

--删除邮件
function del_mail(mailid)
    local sql = string.format('delete from mail where id = %d', mailid)
    print(sql)
end

--读取邮件
function load_mail(mailid)
    local sql = string.format('select id, uid from mail where id = %d', mailid)
    print(sql)
end

--读取邮件列表
function load_mail_list(uid)
    log('读取邮件列表')
end

--提取附件
function get_mail_attachment(uid, mailid)
    log('提取附件')
end

--插入邮件
function inset_mail(uid, uid, uname, recv_uid, recv_uname, title, text)
end






