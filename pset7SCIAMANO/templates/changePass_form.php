<form action="changePass.php" method="post">
    <fieldset>
        <div class="form-group">
            <h5>Please Enter The Old Password</h5>
            <input autofocus class="form-control" name="oldPass" placeholder="Old Password" type="password"/>
        </div>
        <div class="form-group">
            <h5>Please Enter the New Password</h5>
            <input class="form-control" name="newPass" placeholder="New Password" type="password"/>
            <input class="form-control" name="confirmPass" placeholder="Re-enter Password" type="password"/>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Change Password</button>
        </div>
    </fieldset>
</form>

